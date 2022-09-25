#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,op[20],m[20],s[20];
void exgcd(int x,int y){
    if(!y)
        a=1,b=0;
    else{
        exgcd(y,x%y);
        int now=a;a=b;
        b=now-b*(x/y);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,ans=0,xx=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>m[i]>>op[i],xx*=m[i];
    for(int i=1;i<=n;i++,a=b=0){
        s[i]=xx/m[i];
        exgcd(s[i],m[i]);
        if(a>=0)
            ans+=op[i]*s[i]*a;
        else
            ans+=op[i]*s[i]*(a+m[i]);
    }
    cout<<ans%xx;
    return 0;
}