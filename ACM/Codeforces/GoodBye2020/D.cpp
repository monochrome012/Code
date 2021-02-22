#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;
int t,n;
int w[N],d[N];
struct Node{
    int id,val;
    bool operator <(const Node k)const{
        return val<k.val;
    }
};
priority_queue<Node>q;
int main() {
    scanf("%d",&t);
    while(t--){
        while(!q.empty()) q.pop();
        ll ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&w[i]);
            d[i]=0;
            q.push((Node){i,w[i]});
            ans+=w[i];
        }
        for(int i=1,u,v;i<n;i++){
            scanf("%d%d",&u,&v);
            d[u]++;d[v]++;
        }
        printf("%lld",ans);
        for(int i=2;i<n;i++){
            while(!q.empty()){
                if(d[q.top().id]==1) q.pop();
                else break;
            }
            d[q.top().id]--;
            ans+=q.top().val;
            printf(" %lld",ans);
        }
        printf("\n");
    }
}