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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;cin>>t;
  while(t--){
    int k;cin>>k;

    int tt=-1,vv=-1;
    for(int i=0;i<k;i++){
      int n;cin>>n;
      vector<vi> conn(n);
      for(int j=0;j<n-1;j++){
        int u,v;cin>>u>>v;
        conn[u-1].push_back(v-1);
        conn[v-1].push_back(u-1);
      }
      for(int j=0;j<n;j++){
        if(conn[j].size()==1){
          tt=i+1;
          vv=conn[j][0]+1;
        }
      }
    }

    if(tt==-1){
      for(int i=2;i<=k;i++){
        cout<<"1 1 "<<i<<" 1\n";
      }
    }else{
      for(int i=1;i<=k;i++){
        if(i==tt)continue;
        cout<<tt<<' '<<vv<<' '<<i<<' '<<"1\n";
      }
    }
  }
}
