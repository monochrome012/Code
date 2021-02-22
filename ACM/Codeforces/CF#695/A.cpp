#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("9");
        for(int i=2,tmp=8;i<=n;i++){
            printf("%d",tmp);
            tmp=(tmp+1)%10;
        }
        printf("\n");
    }
    return 0;
}