#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("fma")
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define x first
#define y second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rep(x) for(int __i=(x);__i>0;--__i)
#define compress(x) sort(all(x)), x.erase(unique(all(x)), x.end())

typedef long long ll;
typedef long double ld;
typedef __int128 i128;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> T sq(T x) { return x*x; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ld PI = acosl(-1);
const ld EPS = 1e-10;

mt19937 rd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> rnd_int(0, 0); // rnd_int(rd)
uniform_real_distribution<double> rnd_real(0, 1); // rnd_real(rd)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;

        vi res(n+1);
        vector<tuple<int, int, int>> v;
        while(m--) {
            int o, i, j; cin >> o >> i >> j;
            if(o==1) {
                if(i==j) res[i]=1;
                else v.push_back({o, i, j});
            } else {
                if(i==j) res[i]=-1;
                else v.push_back({o, i, j});
            }
        }

        bool chk=true;
        vvi conn(n+1);
        vi inDegree(n+1);
        for(auto [o, i, j]:v) {
            if(o==1) {
                if(res[i]>0 && res[j]<0) {
                    conn[j].push_back(i);
                    inDegree[i]++;
                } else if(res[i]<0 && res[j]>0) {
                    conn[i].push_back(j);
                    inDegree[j]++;
                } else if(res[i]<0 && res[j]<0) {
                    chk=false;
                }
            } else {
                if(res[i]>0 && res[j]<0) {
                    conn[i].push_back(j);
                    inDegree[j]++;
                } else if(res[i]<0 && res[j]>0) {
                    conn[j].push_back(i);
                    inDegree[i]++;
                } else if(res[i]>0 && res[j]>0) {
                    chk=false;
                }
            }
        }
        if(!chk) {
            cout << "NO\n";
            continue;
        }

        queue<int> q;
        for(int i=1;i<=n;i++) {
            if(!inDegree[i]) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int cur=q.front(); q.pop();
            for(int nxt:conn[cur]) {
                if(res[nxt]<0) res[nxt]=min(res[nxt], -res[cur]-1);
                else res[nxt]=max(res[nxt], -res[cur]);
                if(--inDegree[nxt]==0) {
                    q.push(nxt);
                }
            }
        }
        for(int i=1;i<=n;i++) {
            if(inDegree[i]) chk=false;
        }
        if(!chk) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for(int i=1;i<=n;i++) cout << res[i] << ' ';
            cout << '\n';
        }
    }
}
