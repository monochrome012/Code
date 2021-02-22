#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
const ll inf=1e18+7;
int n,m;
int p[N],edn;
struct Edge{
    int v,w,nxt;
}e[N*2];
void add(int u,int v,int w){
    e[++edn]=(Edge){v,w,p[u]};p[u]=edn;
    e[++edn]=(Edge){u,w,p[v]};p[v]=edn;
}
struct Node{
    int id,ad,mi;
    ll val;
    bool operator<(const Node k)const{
        return val>k.val;
    }
};
priority_queue<Node>q;
ll dis[N][2][2];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        p[i]=-1;
        for(int j=0;j<2;j++) for(int k=0;k<2;k++) dis[i][j][k]=inf;
    } 
    edn=-1;
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    q.push((Node){1,0,0,0});
    dis[1][0][0]=0;
    while(!q.empty()){
        Node t=q.top();q.pop();
        if(dis[t.id][t.ad][t.mi]<t.val) continue;
        ///printf("id=%d  mx=%d  mi=%d  val=%lld\n",t.id,t.ad,t.mi,t.val);
        int u=t.id;
        for(int i=p[u];~i;i=e[i].nxt){
            int v=e[i].v;
            ll vval=t.val+e[i].w;
            if(t.ad==0&&t.val+e[i].w*2<dis[v][1][t.mi]){
                dis[v][1][t.mi]=t.val+e[i].w*2;
                q.push((Node){v,1,t.mi,dis[v][1][t.mi]});
            }
            if(t.mi==0&&t.val<dis[v][t.ad][1]){
                dis[v][t.ad][1]=t.val;
                q.push((Node){v,t.ad,1,dis[v][t.ad][1]});
            }
            if(t.mi==0&&t.ad==0&&t.val+e[i].w<dis[v][1][1]){
                dis[v][1][1]=t.val+e[i].w;
                q.push((Node){v,1,1,dis[v][1][1]});
            }
            if(t.val+e[i].w<dis[v][t.ad][t.mi]){
                dis[v][t.ad][t.mi]=t.val+e[i].w;
                q.push((Node){v,t.ad,t.mi,dis[v][t.ad][t.mi]});
            }
        }
    }   
    for(int i=2;i<=n;i++){
        printf("%lld ",dis[i][1][1]);
    }

}