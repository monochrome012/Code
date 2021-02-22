#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int t,n,k;
int h[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&h[i]);
        }
        bool flag=true;
        int lo=h[1],hi=h[1]+k-1;
        for(int i=2;flag&&i<n;i++){
            if(hi<h[i]) flag=false;
            if(lo-k+1>h[i]+k-1) flag=false;
            lo=max(h[i],lo-k+1);
            hi=min(h[i]+k+k-2,hi+k-1);
            ///printf("%d  %d  %d\n",lo,hi,flag);
        }
        if(lo-k+1>h[n]||hi<h[n]) flag=false;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}