#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int t,n;
char a[N],b[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%s%s",&n,a,b);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]>b[i]) cnt++;
            if(a[i]<b[i]) cnt--;
        }
        if(cnt>0) printf("RED\n");
        else if(cnt<0) printf("BLUE\n");
        else printf("EQUAL\n");
    }
}