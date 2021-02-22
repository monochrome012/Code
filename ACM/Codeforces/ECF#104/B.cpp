#include <bits/stdc++.h>
using namespace std;
const int N=500;
string s,t;
string ss,tt;
int q;
int main() {
    scanf("%d",&q);
    while(q--){
        ss=tt="";
        cin>>s>>t;
        int ls=s.length(),lt=t.length();
        int lcm=ls*lt/__gcd(ls,lt);                  
        for(int i=1;i<=lcm/ls;i++) ss+=s;
        for(int i=1;i<=lcm/lt;i++) tt+=t;
        if(ss==tt) cout<<ss<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}