#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n,m,a[N],ls[N],rs[N],p[N],f[N];
void clear(int x){ls[x]=rs[x]=p[x]=0;}
int find(int x){
    if(f[x]==x)
        return x;
    return f[x]=find(f[x]);
}
int hb(int x,int y){
    if(!x||!y)
        return x+y;
    if(a[x]<a[y])
        swap(x,y);
    f[rs[x]=hb(rs[x],y)]=x;
    p[x]=(!rs[x]?0:p[rs[x]]+1);
    if(p[ls[x]]<p[rs[x]])
        swap(ls[x],rs[x]);
    return x;
}
int hurt(int x){
    a[x]>>=1;
    int fa_now=hb(ls[x],rs[x]);
    clear(x);
    f[fa_now]=f[x]=hb(fa_now,x);
    return f[x];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin>>n){
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cin>>m;
        for(int i=1;i<=n;i++){
            f[i]=i;
            clear(i);
        }
        while(m--){
            int x,y,fax,fay,nowl,nowr;
            cin>>x>>y;
            fax=find(x),fay=find(y);
            if(fax==fay)
                cout<<"-1\n";
            else{
                int nowl=hurt(fax),nowr=hurt(fay);
                f[nowl]=f[nowr]=hb(nowl,nowr);
                cout<<a[f[nowl]]<<'\n';
            }
        }
    }
    return 0;
}