#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n;
int a[2000000];
int main() {
    scanf("%d",&n);
    int le=0,ri=n+1;
    int m=100;
    a[0]=a[n+1]=n+1;
    while(ri-le-1>m){
        int f=(ri-le+1)/3;
        int l=le+f-1;
        int r=ri-f+1;
        printf("? %d\n",l);fflush(stdout);
        scanf("%d",&a[l]);
        printf("? %d\n",r);fflush(stdout);
        scanf("%d",&a[r]);
        m-=2;
        if(a[l]<a[r]){ri=r;continue;}
        if(a[r]<a[l]){le=l;continue;}
    }
    for(int i=le+1;i<ri;i++){
        printf("? %d\n",i);fflush(stdout);
        scanf("%d",&a[i]);
    }
    for(int i=le+1;i<ri;i++){
        if(a[i]<a[i-1]&&a[i]<a[i+1]){
            printf("! %d\n",i);fflush(stdout);
            break;
        }
    }

}
