#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
struct Edge{
    int v,nxt;
}e[N*2];
int hd[N],edn;
void add(int u,int v){
    e[++edn]=(Edge){v,hd[u]};hd[u]=edn;
    e[++edn]=(Edge){u,hd[v]};hd[v]=edn;
}
int n,a[N];
int le[N],ri[N],id[N],tot,fa[N][22],d[N];
void dfs(int u,int f){
    tot++;
    le[u]=tot;
    id[tot]=u;
    for(int i=hd[u];~i;i=e[i].nxt){
        int v=e[i].v;
        if(v==f) continue;
        fa[v][0]=u;
        d[v]=d[u]+1;
        dfs(v,u);
    }
    ri[u]=tot;
}
int lca(int x,int y){
    if(d[x]<d[y]) swap(x,y);
    for(int i=20;i>=0;i--){
        if(d[fa[x][i]]>=d[y]) x=fa[x][i];
    }
    if(x==y) return x;
    for(int i=20;i>=0;i--){
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
}
map<int,int>mp;
queue<int>q[N];
int sum[N];
int main() {
    edn=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
       scanf("%d",&a[i]);
       mp[a[i]]=i;
       hd[i]=-1;
    }
    for(int i=1,u,v;i<n;i++){
       scanf("%d%d",&u,&v);
       add(u,v);
    }
    d[1]=1;
    dfs(1,0);
    for(int i=1;i<=n;i++){
        int u=id[i];
        q[mp[a[u]]].push(u);
    }
    for(int i=1;i<=20;i++){
        for(int j=1;j<=n;j++){
            fa[j][i]=fa[fa[j][i-1]][i-1];
        }
    }
    bool flag=true;
    
    for(int i=1;flag&&i<=n;i++){
        if(q[i].empty()) continue;
        int u=q[i].front();q[i].pop();
        if(q[i].empty()) continue;
        int rt=1;
        while(!q[i].empty()){
            int v=q[i].front();q[i].pop();
            int p=lca(u,v);
            if(fa[v][0]==u){flag=false;break;}
            if(lca(rt,v)!=rt){flag=false;break;}
            if(lca(rt,u)!=rt){flag=false;break;}
            if(p==u){
                rt=v;
                for(int j=20;j>=0;j--){
                    if(d[fa[rt][j]]>=d[p]+1) 
                    rt=fa[rt][j];
                }
                sum[1]--;
                sum[le[rt]]++;
                sum[ri[rt]+1]--;
                sum[le[v]]--;
                sum[ri[v]+1]++;
            }
            else{
                sum[le[u]]--;
                sum[ri[u]+1]++;
                sum[le[v]]--;
                sum[ri[v]+1]++;
            }
            u=v;
        }
        
    }
    
    int ans=0;
    for(int i=1;i<=n;i++){
        sum[i]+=sum[i-1];
        if(sum[i]>=0) ans++;
    }
    if(flag==false) ans=0;
    printf("%d\n",ans);
    
}