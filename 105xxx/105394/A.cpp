#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> conn(200'001);
bool vis[200'001];

int dfs(int cur) {
    int r=1;
    vis[cur]=true;
    for(int nxt:conn[cur]) {
        if(!vis[nxt]) {
            r+=dfs(nxt);
        }
    }
    return r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;cin>>n>>m;
    while(m--) {
        int u,v;cin>>u>>v;
        conn[u].push_back(v);
        conn[v].push_back(u);
    }

    int r=0;
    for(int i=1;i<=n;i++) if(!vis[i]) r=max(r,dfs(i));
    cout << r;
}
