#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int t;
int n,m;
int c[N],k[N],cnt[N];
priority_queue<int>q;
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            scanf("%d",&k[i]);
            cnt[k[i]]++;
        } 
        for(int i=1;i<=m;i++){
            scanf("%d",&c[i]);
        }
        for(int i=m;i>=1;i--){
            for(int j=1;j<=cnt[i];j++) q.push(c[i]);
            if(q.empty()||q.top()<=c[i]) continue;
            q.pop();q.push(c[i]);
            
        }
        long long ans=0;
        while(!q.empty()) ans+=q.top(),q.pop();
        printf("%lld\n",ans);
    }
}