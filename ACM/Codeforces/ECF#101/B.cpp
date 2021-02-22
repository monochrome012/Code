#include <bits/stdc++.h>
using namespace std;
const int N=300;
int t,n,m;
int a[N],b[N],sa[N],sb[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sa[i]=sa[i-1]+a[i];
        } 
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
            sb[i]=sb[i-1]+b[i];
        } 
        int ans=0;
        for(int i=1;i<=n+m;i++){
            for(int j=0;j<=n&&j<=i;j++){
                if(i-j>m) continue;
                ans=max(ans,sa[j]+sb[i-j]);
            }
        }
        printf("%d\n",ans);
    }
}