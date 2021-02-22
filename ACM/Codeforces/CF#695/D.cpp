#include <bits/stdc++.h>
using namespace std;
const int N=5e3+7;
const int mod=1e9+7;
int n,k,q;
int a[N];
int dp[N][N];
int cnt[N];
int p,x;
int main() {
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
        scanf("%d",&a[i]);
    } 
    for(int j=1;j<=k;j++){
        for(int i=1;i<=n;i++){
            dp[i][j]=(dp[i-1][j-1]+dp[i+1][j-1])%mod;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            cnt[i]=(cnt[i]+1ll*dp[i][j]*dp[i][k-j]%mod)%mod;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+1ll*cnt[i]*a[i]%mod)%mod;
    }
    while(q--){
        scanf("%d%d",&p,&x);
        ans=(ans-1ll*cnt[p]*a[p]%mod+mod)%mod;
        a[p]=x;
        ans=(ans+1ll*cnt[p]*x%mod+mod)%mod;
        printf("%d\n",ans);
    }
}