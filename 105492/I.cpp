#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("fma")
using namespace std;
typedef long long ll;

ll t[10001],f[10001],p[100],d[100],c[100],dp[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>t[i]>>f[i];
    for(int i=0;i<k;i++)cin>>p[i]>>d[i]>>c[i];
    for(int i=1;i<=n;i++) {
        dp[i]=dp[i-1]+f[i];
        for(int j=0;j<k;j++) {
            for(int kk=max(0LL, i-d[j]+1);kk<=i;kk++) {
                if(t[i]-t[kk]+1<=p[j]) {
                    dp[i]=min(dp[i],(kk-1>=0 ? dp[kk-1] : 0)+c[j]);
                    break;
                }
            }
        }
    }
    cout<<dp[n];
}
