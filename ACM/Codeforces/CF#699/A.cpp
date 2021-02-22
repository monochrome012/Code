#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int t,x,y,n;
char s[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&x,&y);
        scanf("%s",s);
        n=strlen(s);
        int r=0,u=0,l=0,d=0;
        for(int i=0;i<n;i++){
            if(s[i]=='R') r++;
            if(s[i]=='U') u++;
            if(s[i]=='L') l++;
            if(s[i]=='D') d++; 
        }
        bool flag=true;
        if(x>=0&&r<x) flag=false;
        if(x<0&&l<-x) flag=false;
        if(y>=0&&u<y) flag=false;
        if(y<0&&d<-y) flag=false;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}