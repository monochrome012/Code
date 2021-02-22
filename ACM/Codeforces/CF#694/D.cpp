#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+7;
const int mod=1e9+7;
int t,n,q;
ll w;
int a[N];
ll hs[N],hs2[N];
bool is[N];
int pri[N],tot;
unordered_map<int,int>mp;
unordered_map<int,ll>mp2;
int main() {
    for(int i=2;i<2000;i++){
        if(!is[i]) pri[++tot]=i;
        for(int j=1;j<=tot;j++){
            if(i*pri[j]>=2000) break;
            is[i*pri[j]]=1;
            if(i%pri[j]==0) break;
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            int tmp=a[i];
            hs[i]=0;
            for(int j=1;j<=tot;j++){
                int cnt=0;
                while(tmp%pri[j]==0) cnt++,tmp/=pri[j];
                if(cnt&1) hs[i]=(hs[i]*23333%mod+pri[j])%mod;
            }
            if(tmp>1) hs[i]=(hs[i]*23333%mod+tmp)%mod;
            if(mp[hs[i]]) mp2[hs[i]]*=a[i];
            else mp2[hs[i]]=a[i];
            mp[hs[i]]++;
            ans=max(ans,mp[hs[i]]);
        } 
        mp.clear();
        int ans2=0;
        for(int i=1;i<=n;i++){
            hs2[i]=0;
            ll tmp=mp2[hs[i]];
            for(int j=1;j<=tot;j++){
                int cnt=0;
                while(tmp%pri[j]==0) cnt++,tmp/=pri[j];
                if(cnt&1) hs2[i]=(hs2[i]*23333%mod+pri[j])%mod;
            }
            if(tmp>1) hs2[i]=(hs2[i]*23333%mod+tmp)%mod;
            mp[hs2[i]]++;
            ans2=max(ans2,mp[hs2[i]]);
        }
        scanf("%d",&q);
        while(q--){
            scanf("%lld",&w);
            if(w==0) printf("%d\n",ans);
            else printf("%d\n",ans2);
        } 
    }
}