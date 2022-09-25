#include<bits/stdc++.h>
using namespace std;
map<string,int>a;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;string c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c;
        a[c]=1;
    }
    cin>>m;
    while(m--){
        cin>>c;
        if(!a[c])
            cout<<"WRONG\n";
        else if(a[c]==1){
            cout<<"OK\n";
            a[c]=2;
        }
        else
            cout<<"REPEAT\n";
    }
    return 0;
}