#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+7;
const ll maxn=1e9+7;
ll n1,n2,n3,a;
int main() {
    scanf("%lld%lld%lld",&n1,&n2,&n3);
    ll sum=0,sum1=0,sum2=0,sum3=0;
    ll m1=maxn,m2=maxn,m3=maxn;
    for(ll i=1;i<=n1;i++){
        scanf("%lld",&a);
        sum+=a;
        sum1+=a;
        m1=min(m1,a);
    }
    for(ll i=1;i<=n2;i++){
        scanf("%lld",&a);
        sum+=a;
        sum2+=a;
        m2=min(m2,a);
    }
    for(ll i=1;i<=n3;i++){
        scanf("%lld",&a);
        sum+=a;
        sum3+=a;
        m3=min(m3,a);
    }
    ll ans=sum-2*min(sum1,min(sum2,sum3));
    ans=max(ans,sum-2*m1-2*m2-2*m3+2*max(m1,max(m2,m3)));
    printf("%lld\n",ans);
}