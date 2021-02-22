#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int t,n;
int a[N];
int b[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[a[i]]++;
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            if(a[i]==a[i-1]) continue;
            if(b[a[i]]) ans++;
            if(b[a[i]]>1){
                if(b[a[i]+1]==0) ans++;
                else b[a[i]+1]++;
            } 
            b[a[i]]=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}