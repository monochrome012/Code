#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n;
int a,b,x,ans;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x==a&&x==b) continue;
        if(x==a) b=x,ans++;
        else if(b==x) a=x,ans++;
        else if(a==b) a=x,ans++;
        else a=x,b=0,ans++;
    }
    printf("%d\n",ans);
}