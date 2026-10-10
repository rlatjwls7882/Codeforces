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

ll l[200'001],r[200'001],p[200'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        ll n,m,k;cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            cin>>l[i]>>r[i];
            p[i]=p[i-1]+r[i]-l[i]+1;
        }

        if(k==0){
            cout<<r[n]+1<<'\n';
            continue;
        }

        ll idx=-1, j=1, kk;
        for(int i=1;i<=n;i++){
            ll R=l[i]+m-1;
            while(j+1<=n&&l[j+1]<=R)j++;

            ll cur=p[j-1]-p[i-1]+min(r[j],R)-l[j]+1;
            if(cur>=k){
                idx=i;
                kk=cur;
            }
        }
        if(idx==-1){
            cout<<"-1\n";
        } else{
            ll rem=kk-k, nxt=l[idx]+m, j=idx;
            while(rem>0){
                while(j<=n&&r[j]<nxt)j++;
                if(j>n){
                    nxt+=rem;
                    rem=0;
                }else if(nxt<l[j]){
                    ll x=min(rem,l[j]-nxt);
                    rem-=x;
                    nxt+=x;
                }else{
                    nxt=r[j]+1;
                }
            }
            cout<<nxt-m<<'\n';
        }
    }
}
