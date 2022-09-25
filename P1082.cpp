#include<bits/stdc++.h>
#define int long long
using namespace std;
int o,p;
void exgcd(int x,int y){
    if(!y){
        o=1;p=0;
        return ;
    }
    exgcd(y,x%y);
    int now=p;
    p=o-x/y*p;o=now;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int a,b;
    cin>>a>>b;
    exgcd(a,b);
    cout<<(o+b)%b<<'\n';
    return 0;
}