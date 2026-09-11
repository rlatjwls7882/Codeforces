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

// 트리의 거리/경로 정보를 centroid ancestor마다 관리할 때 사용
// 0-based, edge() 후 build()
// par[u]: centroid tree 부모, dep[u]: centroid tree 깊이
struct Centroid{
    vector<vi>g;vi sz,par,dep;
    Centroid(int n):g(n),sz(n),par(n,-2),dep(n){}
    void edge(int u,int v){g[u].push_back(v);g[v].push_back(u);}
    int getSize(int u,int p=-1){
        sz[u]=1;
        for(int v:g[u])if(v!=p&&par[v]==-2)sz[u]+=getSize(v,u);
        return sz[u];
    }
    int getCentroid(int u,int p,int n){
        for(int v:g[u])if(v!=p&&par[v]==-2&&sz[v]>n/2)return getCentroid(v,u,n);
        return u;
    }
    int build(int u=0,int p=-1){
        int c=getCentroid(u,-1,getSize(u));
        par[c]=p;if(p>=0)dep[c]=dep[p]+1;
        for(int v:g[c])if(par[v]==-2)build(v,c);
        return c;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    Centroid ct(n);
    for(int i=0;i<n-1;i++) {
        int u,v;cin>>u>>v;
        ct.edge(u-1,v-1);
    }
    ct.build();
    for(int i=0;i<n;i++) cout << char(ct.dep[i]+'A') << ' ';
}
