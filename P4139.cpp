#include<bits/stdc++.h>
using namespace std;
const int N=1e7+2;
int k,ph[N],pr[N];
int quick_pow(int x,int y,int mod){
    int s=1;
    while(y){
        if(y&1)
            s=1ll*s*x%mod;
        x=1ll*x*x%mod;y>>=1;
    }
    return s;
}
int find(int x){
    if(x==1)
        return 0;
    else
        return quick_pow(2,find(ph[x])+ph[x],x);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;ph[1]=1;
    cin>>t;
    for(int i=2;i<=1e7;i++){
        if(!ph[i])
            pr[++k]=i,ph[i]=i-1;
        for(int j=1;j<=k&&pr[j]*i<=1e7;j++){
            ph[pr[j]*i]=ph[i]*(pr[j]-1);
            if(i%pr[j]==0){
                ph[pr[j]*i]+=ph[i];
                break;
            }
        }
    }
    while(t--){
        int x;cin>>x;
        cout<<find(x)<<'\n';
    }
    return 0;
}