#include <bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n;
int a[N],dp[N];
int le[N];
int num[N],cnt[N];
int ri[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        ri[a[i]]=i;
    }
    int ans=0;
    for(int i=n;i>=1;i--){
        num[a[i]]++;
        dp[i]=max(dp[i+1],num[a[i]]);
        if(num[a[i]]==cnt[a[i]]){
            dp[i]=max(dp[i+1],num[a[i]]+dp[ri[a[i]]+1]);
        }
    }
    printf("%d\n",n-dp[1]);
}