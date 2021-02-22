#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int t,n,a[N];
bool is(int x){
    if(x<=1||x>=n) return false; 
    if(a[x]>a[x-1]&&a[x]>a[x+1]) return true;
    if(a[x]<a[x-1]&&a[x]<a[x+1]) return true;
    return false;
}
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int cg=0,ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            if(is(i)) ans++;
            int tmp=a[i];
            int bf=is(i-1)+is(i)+is(i+1);
            a[i]=a[i-1];
            cg=min(cg,is(i-1)+is(i)+is(i+1)-bf);
            a[i]=a[i+1];
            cg=min(cg,is(i-1)+is(i)+is(i+1)-bf);
            a[i]=tmp;
        }
        ans+=cg;
        printf("%d\n",ans);
    }
    return 0;
}