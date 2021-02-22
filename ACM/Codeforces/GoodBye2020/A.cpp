#include <bits/stdc++.h>
using namespace std;
const int N=55;
int t,n;
int a[N],vis[N];
int main() {
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof(vis)); 
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            for(int j=1;j<=i;j++){
                vis[abs(a[i]-a[j])]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=50;i++) ans+=vis[i];
        printf("%d\n",ans);
    }
}