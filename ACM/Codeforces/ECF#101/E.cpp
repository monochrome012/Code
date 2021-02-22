#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int q,n,k,bk;
char s[N];
map<int,int>mp;
int zero[N];
int ans,it;
int main() {
    scanf("%d",&q);
    while(q--){
        mp.clear();
        scanf("%d %d\n",&n,&k);
        scanf("%s",s+1);
        it=min(20,k);
        int len=strlen(s+1);
        for(int i=1;i<=len;i++){
            if(s[i]=='1') zero[i]=zero[i-1]+1;
            else zero[i]=0;
        }
        for(int i=it;i<=len;i++){
            int tmp=0;
            for(int j=i-it+1;j<=i;j++){
                if(s[j]=='0') tmp=tmp*2+1;
                else tmp*=2;
            }
            mp[tmp]=max(mp[tmp],zero[i-it]);
            ///printf("######%d  %d\n",tmp,mp[tmp]);
        }
        int le=k-it;
        ans=0;
        while(1){
            ///printf("%d>>%d>>%d\n",ans,mp.count(ans)?mp[ans]:-1,le);
            if(!mp.count(ans)||mp[ans]<le) break;
            ans++;
            if((ans>=(1<<it))) break;
        }
        if(ans>=(1<<it)){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        int ri=0;
        while((1<<ri)<=ans) ri++;
        for(int i=1;i<=k-ri;i++) printf("0");
        for(int i=ri-1;i>=0;i--){
            if(ans&(1<<i)) printf("1");
            else printf("0");
        }
        printf("\n");
    }

}
/*
2
4 2
0110
4 2
1001
*/