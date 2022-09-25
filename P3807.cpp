#include<bits/stdc++.h>
#define int long long
using namespace std;
int quick_pow(int x,int y,int mod){
    int s=1;
    while(y){
        if(y&1)
            s=s*x%mod;
        x=x*x%mod;y>>=1;
    }
    return s;
}
int lucas(int x,int y,int mod){
    if(x<y)
        return 0;
    if(x>=mod||y>=mod)
        return lucas(x/mod,y/mod,mod)*lucas(x%mod,y%mod,mod)%mod;
    int o,p;o=p=1;
    for(int i=1;i<=x-y;i++)
        p=p*i%mod;
    for(int i=y+1;i<=x;i++)
        o=o*i%mod;
    return o*quick_pow(p,mod-2,mod)%mod;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t,n,m,p;cin>>t;
    while(t--){
        cin>>n>>m>>p;
        cout<<lucas(n+m,n,p)<<'\n';
    }
    return 0;
}