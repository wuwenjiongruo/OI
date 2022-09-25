#include<bits/stdc++.h>
#define int long long
#define ls (x<<1)
#define rs (x<<1|1)
using namespace std;
const int N=1e5+2;
struct lfxxx{int nxt,o,z;}a[N<<1];
int n,m,kk,cnt,h[N],s[N],op[N];
int mx[N<<2],mn[N<<2];
int f[N],high[N],top[N],siz[N],df[N],fat[N];
void add(int x,int y,int z){a[++kk].nxt=y;a[kk].z=z;a[kk].o=h[x];h[x]=kk;}
void dfs1(int x,int fa){
    f[x]=fa;high[x]=high[fa]+1;siz[x]=1;
    for(int i=h[x];i;i=a[i].o)
        if(a[i].nxt!=fa){
            int nx=a[i].nxt;
            dfs1(nx,x);
            siz[x]+=siz[nx];s[nx]=a[i].z;
            if(siz[nx]>siz[fat[x]])
                fat[x]=nx;
        }
}
void dfs2(int x,int topp){
    top[x]=topp;df[x]=++cnt;op[cnt]=s[x];
    if(!fat[x])
        return ;
    dfs2(fat[x],topp);
    for(int i=h[x];i;i=a[i].o)
        if(a[i].nxt!=f[x]&&a[i].nxt!=fat[x])
            dfs2(a[i].nxt,a[i].nxt);
}
void push_up(int x){mx[x]=max(mx[ls],mx[rs]);mn[x]=min(mn[ls],mn[rs]);}
void build(int l,int r,int x){
    if(l==r){
        mx[x]=mn[x]=op[l];
        return ;
    }
    int mid=((l+r)>>1);
    build(l,mid,ls);
    build(mid+1,r,rs);
    push_up(x);
}
int ask(int l,int r,int nowl,int nowr,int x){
    if(nowl>=l&&nowr<=r)
        return mx[x];
    int mid=((nowl+nowr)>>1),xx=LONG_LONG_MIN;
    if(l<=mid)
        xx=ask(l,r,nowl,mid,ls);
    if(r>mid)
        xx=max(xx,ask(l,r,mid+1,nowr,rs));
    return xx;
}
int query(int l,int r,int nowl,int nowr,int x){
    if(nowl>=l&&nowr<=r)
        return mn[x];
    int mid=((nowl+nowr)>>1),xx=LONG_LONG_MAX;
    if(l<=mid)
        xx=query(l,r,nowl,mid,ls);
    if(r>mid)
        xx=min(xx,query(l,r,mid+1,nowr,rs));
    return xx;
}
int ask1(int x,int y){
    int xx=LONG_LONG_MAX;
    while(top[x]!=top[y]){
        if(high[top[x]]<high[top[y]])
            swap(x,y);
        xx=min(xx,query(df[top[x]],df[x],1,n,1));
        x=f[top[x]];
    }
    if(high[x]<high[y])
        swap(x,y);
    return min(xx,query(df[y]+1,df[x],1,n,1));
}
int ask2(int x,int y){
    int xx=LONG_LONG_MIN;
    while(top[x]!=top[y]){
        if(high[top[x]]<high[top[y]])
            swap(x,y);
        xx=max(xx,ask(df[top[x]],df[x],1,n,1));
        x=f[top[x]];
    }
    if(high[x]<high[y])
        swap(x,y);
    return max(xx,ask(df[y]+1,df[x],1,n,1));
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1,x,y,z;i<n;i++){
        cin>>x>>y>>z;
        add(x,y,z);add(y,x,z);
    }
    dfs1(1,1);dfs2(1,1);build(1,n,1);
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        cout<<ask1(x,y)<<' '<<ask2(x,y)<<'\n';
    }
    return 0;
}