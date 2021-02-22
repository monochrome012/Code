#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int t,n,m;
int a[N],b[N],c[N];
int ans[N];
vector<int>vc[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);

        for(int i=1;i<=n;i++) vc[i].clear();
        for(int i=1;i<=m;i++) ans[i]=0;

        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        
        for(int i=1;i<=m;i++){
            scanf("%d",&c[i]);
            vc[c[i]].push_back(i);
        } 

        bool flag=true;
        for(int i=1;flag&&i<=n;i++){
            if(a[i]!=b[i]){
                if(vc[b[i]].size()<=0){
                    flag=false;break;
                }
                ans[vc[b[i]].back()]=i;
                vc[b[i]].pop_back();
            } 
        }
        if(ans[m]==0){
            for(int i=1;i<=n;i++){
                if(b[i]==c[m]){ans[m]=i;break;}
            }
        }
        if(ans[m]==0) flag=false;
        if(flag==false){printf("NO\n");continue;}
        printf("YES\n");
        for(int i=1;i<=m;i++){
            if(ans[i]==0) ans[i]=ans[m];
            printf("%d%c",ans[i],i==m?'\n':' ');
        }
        
    }
}