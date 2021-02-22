#include <bits/stdc++.h>
using namespace std;
const int N=107;
int n;
int a[N],b[N],sa[N],sb[N],dp[N][N][N*N];
int main() {
    memset(dp,-1,sizeof(dp)); dp[0][0][0]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
        sa[i]=sa[i-1]+a[i];
        sb[i]=sb[i-1]+b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=sa[i];k++){
                if(dp[i-1][j][k]!=-1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
                if(k-a[i]>=0&&j>=1&&dp[i-1][j-1][k-a[i]]!=-1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-a[i]]+b[i]);
                
             ///   printf("%d>>%d>>%d>>%d   %d\n",i,j,k,dp[i][j][k],dp[i-1][j-1][k-a[i]]);
            }
        }
    }
    double ans=0;
    for(int i=1;i<=n;i++){
        ans=0;
        for(int j=0;j<=sa[n];j++){
            if(dp[n][i][j]==-1) continue;
            ans=max(ans,min(1.0*j,1.0*(sb[n]-dp[n][i][j])/2+dp[n][i][j]));
        }
        printf("%.10f ",ans);
    }
}