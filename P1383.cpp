#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n,cnt,rt[N];
int ls[N<<5],rs[N<<5],s[N<<5];char c[N<<5];
int clo(int x){
    ++cnt;
    ls[cnt]=ls[x];rs[cnt]=rs[x];s[cnt]=s[x];c[cnt]=c[x];
    return cnt;
}
int update(int l,int r,int x,char k){
    x=clo(x);
    if(l==r){
        s[x]=1;c[x]=k;
        return x;
    }
    int mid=((l+r)>>1);
    if(s[ls[x]]==mid-l+1)
        ls[x]=update(l,mid,ls[x],k);
    else
        rs[x]=update(mid+1,r,rs[x],k);
    s[x]=s[ls[x]]+s[rs[x]];
    return x;
}
char ask(int l,int r,int x,int k){
    if(l==r)
        return c[x];
    int mid=((l+r)>>1);
    if(s[ls[x]]>=k)
        return ask(l,mid,ls[x],k);
    else
        return ask(mid+1,r,rs[x],k-s[ls[x]]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        char op,x;int y;
        cin>>op;
        if(op=='T')
            cin>>x,cnt++,rt[cnt]=update(1,n,rt[cnt],x);
        else if(op=='U'){
            cin>>y;cnt++;
            ls[cnt]=ls[cnt-y+1];rs[cnt]=rs[cnt-y+1];
            s[cnt]=s[cnt-y+1];c[cnt]=c[cnt-y+1];
        }
        else{
            cin>>y;
            cout<<ask(1,n,rt[cnt],y)<<'\n';
        }
    }
    return 0;
}