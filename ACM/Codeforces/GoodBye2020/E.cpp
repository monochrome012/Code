#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
const int mod=1e9+7;
int t,n;
ll x[N];
int num[100];
int main() {
    scanf("%d",&t);
    while(t--){
        memset(num,0,sizeof(num));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
            for(int j=0;j<60;j++){
                if(x[i]&(1ll<<j)) num[j]++;
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll sum1=0,sum2=0;
            for(int j=0;j<60;j++){
                if(x[i]&(1ll<<j)){
                    sum1=(sum1+(1ll<<j)%mod*num[j]%mod)%mod;
                    sum2=(sum2+(1ll<<j)%mod*n%mod)%mod;
                } 
                else sum2=(sum2+(1ll<<j)%mod*num[j]%mod)%mod;
            }
            ans=(ans+sum1*sum2%mod)%mod;
        }
        printf("%lld\n",ans);
    }

}