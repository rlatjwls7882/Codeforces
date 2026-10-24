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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        int n;string s;cin>>n>>s;

        ll r=1;
        bool c0=1,c1=1, q1=1;
        for(int i=0;i<n;i+=2) {
            if(s[i]!='?') {
                q1=0;
                if(s[i]-'0'!=(i/2)%2) c0=0;
                if(s[i]-'0'!=(i/2+1)%2) c1=0;
            }
        }
        bool d0=1,d1=1, q2=1;
        for(int i=1;i<n;i+=2) {
            if(s[i]!='?') {
                q2=0;
                if(s[i]-'0'!=(i/2)%2) d0=0;
                if(s[i]-'0'!=(i/2+1)%2) d1=0;
            }
        }
        if((c0 || c1) && (d0 || d1)) {
            if(q1) r*=2;
            if(q2) r*=2;
        } else {
            r=0;
        }
        cout << r<<'\n';
    }
}
