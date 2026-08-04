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
        int n; string a, b; cin >> n >> a >> b;
        if(n<3) {
            if(a!=b) cout << "-1\n";
            else cout << "0\n";
            continue;
        }

        vector<int> a1, a2, b1, b2;
        for(int i=0;i<n;i++) {
            if(a[i]=='1') {
                if(i&1) a1.push_back(i);
                else a2.push_back(i);
            }
            if(b[i]=='1') {
                if(i&1) b1.push_back(i);
                else b2.push_back(i);
            }
        }
        if(sz(a1)==sz(b1) && sz(a2)==sz(b2)) {
            ll cnt=0;
            for(int i=0;i<sz(a1);i++) cnt+=abs(a1[i]-b1[i])/2;
            for(int i=0;i<sz(a2);i++) cnt+=abs(a2[i]-b2[i])/2;
            cout<<cnt<<'\n';
        } else {
            cout << "-1\n";
        }
    }
}
