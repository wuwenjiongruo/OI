#include<bits/stdc++.h>
#define int long long
using namespace std;
int ba[114];
void update(int x){
    for(int i=50;i>=0;i--)
        if(x&(1<<i)){
            if(ba[i])
                x^=ba[i];
            else{
                ba[i]=x;
                return ;
            }
        }
}
int ask(){
    int xx=0;
    for(int i=50;i>=0;i--)
        xx=max(xx,xx^ba[i]);
    return xx;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        update(x);
    }
    cout<<ask();
    return 0;
}