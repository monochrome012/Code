#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int t,n,d;
int a[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        if(a[n]<=d||a[1]+a[2]<=d) printf("YES\n");
        else printf("NO\n");
    }
}