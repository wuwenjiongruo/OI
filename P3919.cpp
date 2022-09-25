#include<bits/stdc++.h>
#define ls lx[x]
#define rs rx[x] 
using namespace std;
const int N=1e6+2;
int lx[N*32],rx[N*32],s[N*32],rt[N],cnt,k,n,m;
int clo(int x){cnt++;lx[cnt]=lx[x];rx[cnt]=rx[x];s[cnt]=s[x];return cnt;}
int build(int l,int r,int x){
    x=++cnt;
    if(l==r){
        cin>>s[x];
        return x;
    }
    int mid=((l+r)>>1);
    ls=build(l,mid,0);
    rs=build(mid+1,r,0);
    return x;
}
int update(int need,int l,int r,int x,int w){
    x=clo(x);
    if(l==r){
        s[x]=w;
        return x;
    }
    int mid=((l+r)>>1);
    if(need<=mid)
        ls=update(need,l,mid,ls,w);
    else
        rs=update(need,mid+1,r,rs,w);
    return x;
}
int ask(int need,int l,int r,int x){
    if(l==r)
        return s[x];
    int mid=((l+r)>>1);
    if(need<=mid)
        return ask(need,l,mid,ls);
    else
        return ask(need,mid+1,r,rs);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rt[0]=build(1,n,0);
    while(m--){
        int x,y,z,op;
        cin>>z>>op>>x;
        if(op==1){
            cin>>y;
            rt[++k]=update(x,1,n,rt[z],y);
        }
        else{
            rt[++k]=clo(rt[z]);
            cout<<ask(x,1,n,rt[z])<<'\n';
        }
    }
    return 0;
}