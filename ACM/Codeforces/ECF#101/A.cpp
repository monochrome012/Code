#include <bits/stdc++.h>
using namespace std;
const int N=200;
int t;
char s[N]; 
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int n=strlen(s);
        if(n%2==0 && s[0]!=')' &&s[n-1]!='(') printf("YES\n");
        else printf("NO\n");
    }
}