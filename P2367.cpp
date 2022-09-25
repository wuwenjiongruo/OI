#include<bits/stdc++.h>
using namespace std;
const int N=5e6+2;
int a[N],b[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=a[i]-a[i-1];
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        b[x]+=z;b[y+1]-=z;
    }
    int mn=1145141919;
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+b[i];
        mn=min(mn,a[i]);
    }
    cout<<mn;
    return 0;
}