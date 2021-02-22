#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e6+7;
ll t;
ll n,x;
struct Node{
    ll a,cnt;
};
queue<Node>q;
int main() {
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&x);
        ll ans=0;
        for(ll i=1,v;i<=n;i++){
            scanf("%lld",&v);
            q.push((Node){v,1});
        }
        bool flag=true;
        while(!q.empty()){
            Node tt=q.front();q.pop();
            ans+=tt.a*tt.cnt;
            if(flag&&tt.a%x==0) q.push((Node){tt.a/x,tt.cnt*x});
            else flag=false; 
        }
        printf("%lld\n",ans);
    }
}