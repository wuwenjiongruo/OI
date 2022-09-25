#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+2,mod=998244353;
int n,ans=1,a[N],tree[N],f[N]={1};
void update(int x,int k){
    for(;x<=n;x+=lowbit(x))
        tree[x]+=k;
}
int ask(int x){
    int s=0;
    for(;x;x-=lowbit(x))
        s+=tree[x];
    return s;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,1);
        f[i]=f[i-1]*i%mod;
    }
    for(int i=1;i<=n;i++){
        ans=(ans+f[n-i]*ask(a[i]-1))%mod;
        update(a[i],-1);
    }
    cout<<ans;
    return 0;
}