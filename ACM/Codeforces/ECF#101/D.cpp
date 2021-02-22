#include <bits/stdc++.h>
using namespace std;
const int N=2e5+77;
int t,n,ans;
int x[N],y[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int now=n;
        ans=0;
        for(int i=n-1;i>=3;i--){
            int ni=i-1;
            ///printf("%d>>%d>>%d\n",now,i,((now+ni-1)/ni+ni-1)/ni);
            if(((now+ni-1)/ni+ni-1)/ni>1){
                ans++,x[ans]=now,y[ans]=i;
                ans++,x[ans]=now,y[ans]=i;
                now=i;
            }
            else{
                ans++,x[ans]=i,y[ans]=now;
            }
        }
        ans++,x[ans]=now,y[ans]=2;
        ans++,x[ans]=now,y[ans]=2;
        printf("%d\n",ans);
        for(int i=1;i<=ans;i++){
            printf("%d %d\n",x[i],y[i]);
        }
    }
}