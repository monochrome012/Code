#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int t,n,x,a[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&x);
        long long ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ans2+=a[i];
            ans1+=(a[i]+x-1)/x;
        } 
        ans2=(ans2+x-1)/x;
        printf("%lld %lld\n",ans2,ans1);
    }
}