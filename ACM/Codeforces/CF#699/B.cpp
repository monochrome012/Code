#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int h[200];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&h[i]);
        }
        int ans=-1;
        while(k--){
            ans=n;
            for(int i=1;i<n;i++){
                if(h[i]>=h[i+1]) continue;
                ans=i;h[i]++;
                break;
            }
            if(ans==n){ans=-1;break;}
        }
        printf("%d\n",ans);
    }
}