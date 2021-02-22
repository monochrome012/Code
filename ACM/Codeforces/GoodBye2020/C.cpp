#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int t;
char s[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        int ans=0;
        for(int i=0;i<len;i++){
            if(i>=1&&s[i-1]==s[i]) s[i]=0,ans++;
            else if(i>=2&&s[i-2]==s[i]) s[i]=0,ans++;
        }
        printf("%d\n",ans);
    }
}