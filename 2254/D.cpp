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
        int n; cin >> n;
        vector<pll> b(n);
        for(int i=0;i<n;i++) {
            cin >> b[i].x;
            b[i].y=i;
        }
        sort(all(b));

        bool chk=true;
        ll cur=1, sum=0;
        vector<ll> res(n);
        for(int i=1;i<n;i++) {
            if(b[i].x!=b[i-1].x) {
                ll req=b[i].x-sum;
                if(req<=0 || req%cur || i-cur-1>=0 && req/cur<=res[b[i-cur-1].y]) chk=false;
                sum+=req;
                for(int j=i-cur;j<i;j++) res[b[j].y]=req/cur;
                cur=1;
            } else {
                cur++;
            }
        }
        if(!chk || b[0].x) {
            cout << "-1\n";
            continue;
        }
        if(b[0].x==b[n-1].x) {
            for(int i=0;i<n;i++) res[i]=1;
        } else {
            for(int i=n-cur;i<n;i++) res[b[i].y]=res[b[n-cur-1].y]+1;
        }
        for(auto e:res) cout << e << ' ';
        cout << '\n';
    }
}
