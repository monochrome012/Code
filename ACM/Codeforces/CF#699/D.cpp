#include <bits/stdc++.h>
using namespace std;
int t,n,m;
char s[2000][2000];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]+1);
        }
        if(m&1){
            printf("YES\n");
            for(int i=0;i<=m;i++){
                printf("%d%c",(i&1)?2:1,i==m?'\n':' ');
            }
            continue;
        }
        int x=0,y=0,z=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(s[i][j]==s[j][i]){
                    x=i;y=j;
                    break;
                }
            }
            if(x) break;
        }
        if(x){
            printf("YES\n");
            for(int i=0;i<=m;i++){
                printf("%d%c",(i&1)?y:x,i==m?'\n':' ');
            }
            continue;
        }
        if(n==2){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        
        if(s[2][1]==s[1][3]) x=2,y=1,z=3;
        if(s[1][2]==s[2][3]) x=1,y=2,z=3;
        if(s[1][3]==s[3][2]) x=1,y=3,z=2;
        if((m/2)&1){
            m-=2; printf("%d %d %d ",x,y,z);
            while(m){printf("%d %d %d %d ",y,x,y,z);m-=4;}
            printf("\n");
        }
        else{
            printf("%d ",y);
            while(m){printf("%d %d %d %d ",x,y,z,y);m-=4;}
            printf("\n");
        }
    }
    
}