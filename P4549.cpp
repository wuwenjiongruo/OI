#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    if(y)
        return gcd(y,x%y);
    return x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,ans=0;
    cin>>n;
    for(int i=1,x;i<=n;i++){
        cin>>x;x=abs(x);
        ans=gcd(ans,x);
    }
    cout<<ans;
    return 0;
}