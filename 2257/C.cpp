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
typedef vector<ll> vll;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> T sq(T x) { return x*x; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ld PI = acosl(-1);
const ld EPS = 1e-10;

mt19937 rd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> rnd_int(0, 0); // rnd_int(rd)
uniform_real_distribution<double> rnd_real(0, 1); // rnd_real(rd)

int p[100'001], par[100'001], sz[100'001], a[100'001];

int find(int x) {
    if(x==par[x]) return x;
    return par[x]=find(par[x]);
}

bool merge(int x, int y) {
    x=find(x);
    y=find(y);
    if(x==y) return false;
    if(x<y) {
        par[y]=x;
        sz[x]+=sz[y];
    } else {
        par[x]=y;
        sz[y]+=sz[x];
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i=2;i<=n;i++) cin >> p[i];
        for(int i=1;i<=n;i++) par[i]=i, sz[i]=0;
        int m; cin >> m;
        for(int i=0;i<m;i++) {
            cin >> a[i];
            sz[a[i]]++;
        }

        set<int> res;
        for(int i=0;i<m;i++) {
            int e=a[i];
            while(e>1) {
                int cur=sz[find(e)];
                if(!merge(e, p[e]) || cur!=sz[find(e)]) {
                    res.insert(e);
                    break;
                }
                e=p[e];
            }
        }
        cout << res.size() << ' ';
        for(auto e:res) cout << e << ' ';
        cout << '\n';
    }
}
