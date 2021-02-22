#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int t,n,m,l,r;
char s[N];
int lv[N],rv[N],ll[N],lr[N],rl[N],rr[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='+') lv[i]=lv[i-1]+1;
            else lv[i]=lv[i-1]-1;
            ll[i]=min(ll[i-1],lv[i]);    
            lr[i]=max(lr[i-1],lv[i]);
        }
        rv[n+1]=rl[n+1]=rr[n+1]=0;
        for(int i=n;i>=1;i--){
            if(s[i]=='+') rv[i]=rv[i+1]+1;
            else rv[i]=rv[i+1]-1;
            rl[i]=min(rl[i+1],rv[i]);
            rr[i]=max(rr[i+1],rv[i]);
        }
        while(m--){
            scanf("%d%d",&l,&r);
            int le=ll[l-1],ri=lr[l-1];
            le=min(le,lv[l-1]+rv[r+1]-rr[r+1]);
            ri=max(ri,lv[l-1]+rv[r+1]-rl[r+1]);
            printf("%d\n",ri-le+1);
        }
    }
}