#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+2;
int n,p,k,a[N],fz[N],fm[N];
int quick_pow(int x,int y){
    int xx=1;
    while(y){
        if(y&1)
            xx=xx*x%p;
        x=x*x%p;y>>=1;
    }
    return xx;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>p>>k;
    int ans=0;fz[0]=1;
    for(int i=1,x;i<=n;i++){
        cin>>a[i];
        fz[i]=fz[i-1]*a[i]%p;
    }
    fm[n+1]=quick_pow(fz[n],p-2);
    for(int i=n;i;i--)
        fm[i]=fm[i+1]*a[i]%p;
    for(int i=1,now=1;i<=n;i++){
        now=now*k%p;
        ans=(ans+fz[i-1]*fm[i+1]%p*now+p)%p;
    }
    cout<<ans;
    return 0;
}