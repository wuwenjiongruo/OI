#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
struct lfxxx{int nxt,o;}b[N<<1];
int n,m,k,cnm,dnm,h[N],ans[N];
int df[N],top[N],siz[N],f[N],high[N],fat[N];
int ls[N*80],rs[N*80],id[N*80],s[N*80],a[N*80];
void add(int x,int y){b[++k].nxt=y;b[k].o=h[x];h[x]=k;}
void dfs1(int x,int fa){
    high[x]=high[fa]+1;siz[x]=1;f[x]=fa;
    for(int i=h[x];i;i=b[i].o)
        if(b[i].nxt!=fa){
            int nx=b[i].nxt;
            dfs1(nx,x);
            siz[x]+=siz[nx];
            if(siz[nx]>siz[fat[x]])
                fat[x]=nx;
        }
}
void dfs2(int x,int topp){
    top[x]=topp;df[x]=++cnm;
    if(!fat[x])
        return ;
    dfs2(fat[x],topp);
    for(int i=h[x];i;i=b[i].o)
        if(b[i].nxt!=f[x]&&b[i].nxt!=fat[x])
            dfs2(b[i].nxt,b[i].nxt);
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(high[top[x]]<high[top[y]])
            swap(x,y);
        x=f[top[x]];
    }
    return high[x]<high[y]?x:y;
}
void push_up(int x){
    if(s[ls[x]]<s[rs[x]])
        s[x]=s[rs[x]],a[x]=a[rs[x]];
    else
        s[x]=s[ls[x]],a[x]=a[ls[x]];
}
void update(int need,int l,int r,int &x,int k){
    if(!x)
        x=++dnm;
    if(l==r){
        a[x]=l;s[x]+=k;
        return ;
    }
    int mid=((l+r)>>1);
    if(need<=x)
        update(need,l,mid,ls[x],k);
    else
        update(need,mid+1,r,rs[x],k);
    push_up(x);
}
int hb(int x,int y,int l,int r){
    if(!x||!y)
        return x+y;
    if(l==r){
        s[x]+=s[y];
        return x;
    }
    int mid=((l+r)>>1);
    ls[x]=hb(ls[x],ls[y],l,mid);
    rs[x]=hb(rs[x],rs[y],mid+1,r);
    push_up(x);
    return x;
}
void answer(int x,int fa){
    for(int i=h[x];i;i=b[i].o)
        if(b[i].nxt!=fa){
            int nx=b[i].nxt;
            answer(nx,x);
            id[x]=hb(id[x],id[nx],1,1e5);
        }
    ans[x]=(!s[id[x]]?0:a[id[x]]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y;i<n;i++){
        cin>>x>>y;
        add(x,y);add(y,x);
    }
    dfs1(1,1);dfs2(1,1);
    while(m--){
        int x,y,z,fa;
        cin>>x>>y>>z;
        fa=lca(x,y);
        if(!fa)
            fa++;
        update(z,)
    }
    return 0;
}