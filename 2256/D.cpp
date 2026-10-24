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

const ll MOD = 998244353;

ll pow(ll a, ll b) {
    ll r=1;
    while(b) {
        if(b&1) r=r*a%MOD;
        b>>=1;
        a=a*a%MOD;
    }
    return r;
}

ll comb(ll n, ll k) {
    if(k<=0) return 1;
    if(k==1) return n;
    ll r=1;
    for(int i=0;i<k;i++) r=r*(n-i)%MOD;
    for(ll i=2;i<=k;i++) r=r*pow(i, MOD-2)%MOD;
    return r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        int n;string s;cin>>n>>s;

        int c1=0, c2=0, r1=0, r2=0;
        for(int i=0;i<n;i++) {
            if(i==0 || s[i]!=s[i-1]) {
                if(s[i]=='0') c1++;
                else c2++;
            } else {
                if(s[i]=='0') r1++;
                else r2++;
            }
        }

        ll r=comb(c1+r1-1, r1)*comb(c2+r2-1,r2)%MOD;
        cout<<r<<'\n';
    }
}
