#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=9;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--){
        int x,y;cin>>x>>y;
        if((x+y)&1)
            cout<<((x+y)%mod*((y-x+1)>>1)%mod)%mod<<'\n';
        else
            cout<<(((x+y)>>1)%mod*(y-x+1)%mod)%mod<<'\n';
    }
    return 0;
}