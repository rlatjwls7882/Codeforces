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

ll cnt(ll x) {
    int ret=0;
    while(x) {
        if(x&1) x--;
        else x/=2;
        ret++;
    }
    return ret;
}

ll op(ll a, ll m, ll bit) {
    ll bb=(a+m-1)/m;
    if((bb&1)!=bit) bb++;
    ll first=cnt(bb);
    ll ret=bb*m-a+first;
    for(ll plus=2;plus<=first/m;plus+=2) {
        ret=min(ret, m*(bb+plus)-a+cnt(bb+plus));
    }
    return ret;
}

ll solve(vi a) {
    ll res=LINF;
    for(int i=0;i<17;i++) {
        ll m=1<<i;
        ll cur=i;
        ll oddMn=LINF;
        for(int j=0;j<sz(a);j++) {
            ll even=op(a[j], m, 0);
            ll odd=op(a[j], m, 1);
            cur+=min(even, odd);
            oddMn=min(oddMn, odd-min(even, odd));
        }
        res=min(res, cur+oddMn);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        cout << solve(v) << '\n';
    }
}
