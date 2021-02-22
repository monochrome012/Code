#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=k*2-n-1;i++) printf("%d ",i);
        for(int i=k*2-n,j=k;i<=k;i++,j--) printf("%d ",j);
        printf("\n");
    }
}