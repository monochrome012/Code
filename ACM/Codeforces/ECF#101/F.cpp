#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e5+7;
const ll inf=1e18;
ll n,k,a[N];
ll t[N<<2],lz[N<<2];
void pd(ll rt,int l,int r){
    if(lz[rt]){
        ll m=l+r>>1;
        t[rt<<1]+=lz[rt]*(m-l+1);
        t[rt<<1|1]+=lz[rt]*(r-m);
        lz[rt<<1]+=lz[rt];
        lz[rt<<1|1]+=lz[rt];
        lz[rt]=0;
    }
}
void upd(ll rt,ll l,ll r,ll L,ll R,ll v){
    if(L<=l&&r<=R){t[rt]+=v*(r-l+1);lz[rt]+=v;return;}
    pd(rt,l,r);
    ll m=l+r>>1;
    if(L<=m) upd(rt<<1,l,m,L,R,v);
    if(m<R) upd(rt<<1|1,m+1,r,L,R,v);
    t[rt]=t[rt<<1]+t[rt<<1|1];
}
ll qlow(ll rt,ll l,ll r){
    if(l==r) return l;
    pd(rt,l,r);
    ll m=l+r>>1;
    if(t[rt<<1]) return qlow(rt<<1,l,m);
    else return qlow(rt<<1|1,m+1,r);
}
ll ask(ll rt,ll l,ll r,ll k){
    if(l==r) return l;
    pd(rt,l,r);
    ll m=l+r>>1;
    if(t[rt<<1]>=k) return ask(rt<<1,l,m,k);
    return ask(rt<<1|1,m+1,r,k-t[rt<<1]);
}
int main() {
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n,greater<ll>() );
    upd(1,0,N-1,0,0,1);
    ll ans=inf;
    for(ll i=1;i<=n;i++){
        ll le=qlow(1,0,N-1);
        ll fi=(a[i]-1)/2;
        ll se=a[i]-1-fi;
        upd(1,0,N-1,le,le,-1);
        upd(1,0,N-1,le+2,le+1+fi,1);
        upd(1,0,N-1,le+2,le+1+se,1);
        if(t[1]>=k) ans=min(ans,ask(1,0,N-1,k));
    }
    if(ans==inf) ans=-1;
    printf("%lld\n",ans);
}