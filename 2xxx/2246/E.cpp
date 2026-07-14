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
uniform_int_distribution<int> rnd_int(0, (1<<30)-1); // rnd_int(rd)
uniform_real_distribution<double> rnd_real(0, 1); // rnd_real(rd)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        cout << "1\n" << flush;
        int o; cin >> o;

        if(o==0) {
            cout << "0 1\n" << flush;
            int r; cin >> r;
            cout << (r&1) << '\n' << flush;
        } else if(o==1) {
            int m1=0, m2=rnd_int(rd)|1;
            cout << m1 << ' ' << m2 << '\n' << flush;
            int r; cin >> r;

            bool zero=r<=1, one=(r^m2)<=1;
            if(zero && !one || one && !zero) {
                cout << (zero ? 0 : 1) << '\n' << flush;
            } else {
                cout << (r&1 ? 0 : 1) << '\n' << flush;
            }
        } else {
            int idx=0;
            for(int i=1;i<30;i++) {
                if(o&(1<<i)) {
                    idx=i;
                    break;
                }
            }
            cout << "0 " << (1<<idx) << "\n" << flush;
            int r; cin >> r;
            cout << ((r&(1<<idx)) ? 0 : 1) << '\n' << flush;
        }
    }
}
