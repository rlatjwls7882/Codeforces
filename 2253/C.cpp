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
        int n, m, x, y; cin >> n >> m >> x >> y;
        vector<int> a(x), b(y);
        for(int i=0;i<x;i++) cin >> a[i];
        for(int i=0;i<y;i++) cin >> b[i];

        set<int, greater<int>> both;
        for(int i=0;i<y;i++) {
            if(lower_bound(a.begin(), a.end(), b[i])!=a.end() && *lower_bound(a.begin(), a.end(), b[i])==b[i]) {
                both.insert(b[i]);
            }
        }

        priority_queue<int, vector<int>, greater<int>> aa, bb;
        for(int i=0;i<x;i++) {
            if(!both.count(a[i])) {
                aa.push(a[i]);
            }
        }
        for(int i=0;i<y;i++) {
            if(!both.count(b[i])) {
                bb.push(b[i]);
            }
        }
        for(auto e:both) {
            if(aa.size()<n || bb.size()>=m && aa.top()<bb.top()) aa.push(e);
            else bb.push(e);
        }
        while(aa.size()>n) aa.pop();
        while(bb.size()>m) bb.pop();

        ll sum=0;
        if(aa.size()!=n || bb.size()!=m) {
            while(!aa.empty()) {
                sum+=aa.top(); aa.pop();
            }
            while(!bb.empty()) {
                sum+=bb.top(); bb.pop();
            }
        } else {
            ll lst1=aa.size() ? aa.top() : 0, lst2=bb.size() ? bb.top() : 0;
            while(!aa.empty()) {
                sum+=aa.top(); aa.pop();
            }
            while(!bb.empty()) {
                sum+=bb.top(); bb.pop();
            }
            sum-=min(lst1, lst2);
        }
        cout << sum << '\n';
    }
}
