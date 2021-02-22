    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const int N=2e5+7;
    int n,m;
    ll a[N],b[N];
    int main() {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",&b[i]);
        }
        if(n>1){
            sort(a+1,a+1+n);
            ll g=a[2]-a[1];
            for(int i=2;i<=n;i++){
                g=__gcd(g,a[i]-a[1]);
            }
            for(int i=1;i<=m;i++){
                printf("%lld ",__gcd(a[1]+b[i],g));
            }
        }
        else{
            for(int i=1;i<=m;i++){
                printf("%lld ",a[1]+b[i]);
            }
        }
    }