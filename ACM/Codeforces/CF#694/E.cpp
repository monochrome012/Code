#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int t,n,m;
int hd[N],edn;
struct Edge{
    int v,nxt;
}e[N*2];
void add(int u,int v){
    e[++edn]=(Edge){v,hd[u]};hd[u]=edn;
    e[++edn]=(Edge){u,hd[v]};hd[v]=edn;
}
int fa[N],col[N];
int fd(int x){return x==fa[x]?x:fa[x]=fd(fa[x]);}
queue<int>q1,q2;
bool in[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) hd[i]=-1,fa[i]=i,col[i]=0,in[i]=false;
        for(int i=1,u,v;i<=m;i++){
            scanf("%d%d",&u,&v);
            add(u,v);
            int fu=fd(u),fv=fd(v);
            fa[fv]=fu;
        }
        int cnt=0;
        for(int i=1;i<=n;i++) cnt+=fd(i)==i;
        if(cnt>1){printf("NO\n");continue;}
        printf("YES\n");
        q1.push(1);in[1]=true;
        cnt=0;
        while(!q1.empty()||!q2.empty()){
            while(!q1.empty()){
                int u=q1.front();q1.pop();
                col[u]=1;
                for(int i=hd[u];~i;i=e[i].nxt){
                    int v=e[i].v;
                    if(col[v]==1) col[u]=2;
                }
                if(col[u]==1){
                    cnt++;
                    for(int i=hd[u];~i;i=e[i].nxt){
                        int v=e[i].v;
                        if(in[v]) continue;
                        in[v]=true;col[v]=2;q2.push(v);
                    }
                }
                else q2.push(u);
            }
            while(!q2.empty()){
                int u=q2.front();q2.pop();
                for(int i=hd[u];~i;i=e[i].nxt){
                    int v=e[i].v;
                    if(in[v]) continue;
                    in[v]=true;
                    q1.push(v);
                }
            }
        }
        printf("%d\n",cnt);
        for(int i=1;i<=n;i++) if(col[i]==1) printf("%d ",i);
        printf("\n");
    }
}