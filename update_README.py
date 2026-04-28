import glob
import os
import time
import requests
from tqdm import tqdm
from urllib.parse import quote

HANDLE = "rlatjwls7882"
README_PATH = "README.md"
PAGE_SIZE = 10000
API_URL = "https://codeforces.com/api"

def cf_get(method, params):
    url = f"{API_URL}/{method}"

    for attempt in range(5):
        try:
            res = requests.get(
                url,
                params=params,
                timeout=20,
                headers={"User-Agent": "cf-readme-updater"}
            )
            res.raise_for_status()
            data = res.json()

            if data["status"] == "OK":
                return data["result"]

            comment = data.get("comment", "")
            if "Call limit exceeded" in comment:
                time.sleep(2.2)
                continue

            raise RuntimeError(comment)

        except Exception as e:
            if attempt == 4:
                raise e
            time.sleep(2.2)

    raise RuntimeError("Codeforces API request failed")


def get_submissions(handle):
    submissions = []
    start = 1

    while True:
        result = cf_get("user.status", {
            "handle": handle,
            "from": start,
            "count": PAGE_SIZE
        })

        submissions.extend(result)

        if len(result) < PAGE_SIZE:
            break

        start += len(result)
        time.sleep(2.2)

    return submissions


def problem_key(problem):
    return (
        str(problem.get("contestId", "")),
        str(problem.get("index", "")),
        problem.get("name", "")
    )


def get_solved_problems(handle):
    submissions = get_submissions(handle)
    solved = {}

    for sub in submissions:
        if sub.get("verdict") != "OK":
            continue

        problem = sub["problem"]
        key = problem_key(problem)

        if key not in solved:
            solved[key] = {
                "contestId": problem.get("contestId"),
                "index": problem.get("index", ""),
                "name": problem.get("name", ""),
                "rating": problem.get("rating"),
                "tags": problem.get("tags", []),
                "language": sub.get("programmingLanguage", ""),
                "time": sub.get("creationTimeSeconds", 0)
            }
    return list(solved.values())


def get_problem_url(problem):
    contest_id = problem["contestId"]
    index = problem["index"]

    if contest_id is None:
        return "https://codeforces.com/problemset"

    # Gym 문제는 보통 contestId가 100000 이상이다.
    if contest_id >= 100000:
        return f"https://codeforces.com/gym/{contest_id}/problem/{index}"

    return f"https://codeforces.com/problemset/problem/{contest_id}/{index}"


def md_escape(s):
    return str(s).replace("|", "\\|").replace("\n", " ").strip()


def get_problem_rating(rating):
    return str(rating) if rating is not None else "Unrated"


def get_solution_path(problem):
    contest_id = str(problem["contestId"])
    index = str(problem["index"])

    ext_name = {
        ".c": "C",
        ".cc": "C++",
        ".cpp": "C++",
        ".cxx": "C++",
        ".java": "Java",
        ".kt": "Kotlin",
        ".py": "Python",
        ".pypy": "PyPy",
        ".rs": "Rust",
        ".go": "Go",
        ".js": "JavaScript",
        ".ts": "TypeScript",
        ".cs": "C#",
        ".txt": "Text"
    }

    patterns = [
        f"{contest_id}{index}.*",
        f"{contest_id}_{index}.*",
        f"{contest_id}-{index}.*",
        f"{contest_id}/{index}.*",
        f"{contest_id}/{index}/*",

        f"Codeforces/{contest_id}{index}.*",
        f"Codeforces/{contest_id}_{index}.*",
        f"Codeforces/{contest_id}-{index}.*",
        f"Codeforces/{contest_id}/{index}.*",
        f"Codeforces/{contest_id}/{index}/*",

        f"**/{contest_id}{index}.*",
        f"**/{contest_id}_{index}.*",
        f"**/{contest_id}-{index}.*",
        f"**/{contest_id}/{index}.*",
        f"**/{contest_id}/{index}/*",
    ]

    files = []
    seen = set()

    for pattern in patterns:
        for file in glob.glob(pattern, recursive=True):
            if os.path.isdir(file):
                continue
            name = os.path.basename(file)
            if name.lower() in {"readme.md", "license"}:
                continue
            ext = os.path.splitext(file)[1].lower()
            if ext == ".md":
                continue
            if file not in seen:
                seen.add(file)
                files.append(file)
    files.sort()

    result = ""
    for file in files:
        ext = os.path.splitext(file)[1].lower()
        lang = ext_name.get(ext, ext[1:].upper() if ext else "Code")

        link = quote(file.replace(os.sep, "/"), safe="/._-()")
        result += f"[{lang}](./{link}) "

    return result.strip()


def sort_key(problem):
    contest_id = problem["contestId"]
    index = problem["index"]

    if contest_id is None:
        contest_id = 10**18

    return (contest_id, index)


def get_header(solved_count):
    header = '<div align="center">\n\n'
    header += "# Codeforces\n\n"
    header += f"[![CodeForces Profile](https://cf.leed.at?id={HANDLE})](https://codeforces.com/profile/{HANDLE})\n\n"
    header += f"### Solved: {solved_count}\n\n"
    header += "자동으로 생성된 Codeforces solved problem 목록입니다.\n\n"
    return header


def get_table(problems):
    table = "| No. | Title | Rating | Solutions |\n"
    table += "|:---|:---|:---:|:---:|\n"

    for problem in tqdm(problems):
        contest_id = problem["contestId"]
        index = problem["index"]

        no = f"{contest_id}{index}" if contest_id is not None else index
        url = get_problem_url(problem)
        title = md_escape(problem["name"])
        rating = get_problem_rating(problem["rating"])
        path = get_solution_path(problem)

        table += f"| [{no}]({url}) | {title} | {rating} | {path} |\n"

    return table


if __name__ == "__main__":
    problems = get_solved_problems(HANDLE)
    problems.sort(key=sort_key)

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(get_header(len(problems)))
        f.write(get_table(problems))
        f.write("</div>\n")
