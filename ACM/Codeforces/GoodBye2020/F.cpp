#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
const int mod=1e9+7;
int fa[N];
int fd(int x){return x==fa[x]?x:fa[x]=fd(fa[x]);}
ll ans=0;
vector<int>vc;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m+1;i++) fa[i]=i;
    for(int i=1,k,u,v;i<=n;i++){
        scanf("%d",&k);
        if(k==1) scanf("%d",&u),v=m+1;
        else scanf("%d%d",&u,&v);
        int fu=fd(u),fv=fd(v);
        if(fu==fv) continue;
        fa[fu]=fv;
        ans=(ans*2+1)%mod;
        vc.push_back(i);
    }
    printf("%lld ",(ans+1)%mod);
    printf("%d\n",vc.size());
    for(auto it:vc){
        printf("%d ",it);
    }
}