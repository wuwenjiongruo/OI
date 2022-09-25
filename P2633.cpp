#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
struct lfxxx{int nxt,o;}a[N<<1];
int n,m,cnt,kk,kkk,h[N],w[N],b[N];
int ls[N<<5],rs[N<<5],s[N<<5],rt[N];
int top[N],f[N],siz[N],fat[N],high[N];
void add(int x,int y){a[++kk].nxt=y;a[kk].o=h[x];h[x]=kk;}
int clo(int x){
    ++cnt;
    ls[cnt]=ls[x];rs[cnt]=rs[x];s[cnt]=s[x]+1;
    return cnt;
}
int update(int need,int l,int r,int x){
    x=clo(x);
    if(l==r)
        return x;
    int mid=((l+r)>>1);
    if(need<=mid)
        ls[x]=update(need,l,mid,ls[x]);
    else
        rs[x]=update(need,mid+1,r,rs[x]);
    s[x]=s[ls[x]]+s[rs[x]];
    return x;
}
int ask(int l,int r,int f,int ff,int nowl,int nowr,int k){
    if(nowl==nowr)
        return nowl;
    int mid=((nowl+nowr)>>1),now=s[ls[l]]+s[ls[r]]-s[ls[f]]-s[ls[ff]];
    if(now>=k)
        return ask(ls[l],ls[r],ls[f],ls[ff],nowl,mid,k);
    else
        return ask(rs[l],rs[r],rs[f],rs[ff],mid+1,nowr,k-now);
}
void dfs1(int x,int fa){
    high[x]=high[fa]+1;siz[x]=1;f[x]=fa;
    rt[x]=update(w[x],1,kkk,rt[fa]);
    for(int i=h[x];i;i=a[i].o)
        if(a[i].nxt!=fa){
            int nx=a[i].nxt;
            dfs1(nx,x);
            siz[x]+=siz[nx];
            if(siz[nx]>siz[fat[x]])
                fat[x]=nx;
        }
}
void dfs2(int x,int topp){
    top[x]=topp;
    if(!fat[x])
        return ;
    dfs2(fat[x],topp);
    for(int i=h[x];i;i=a[i].o)
        if(a[i].nxt!=f[x]&&a[i].nxt!=fat[x])
            dfs2(a[i].nxt,a[i].nxt);
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(high[top[x]]<high[top[y]])
            swap(x,y);
        x=f[top[x]];
    }
    return high[x]<high[y]?x:y;
}
int find(int l,int r,int x){
    while(l<r){
        int mid=((l+r+1)>>1);
        if(b[mid]>x)
            r=mid-1;
        else
            l=mid;
    }
    return l;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>w[i],b[i]=w[i];
    sort(b+1,b+n+1);
    kkk=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++)
        w[i]=find(1,kkk,w[i]);
    for(int i=1,x,y;i<n;i++){
        cin>>x>>y;
        add(x,y);add(y,x);
    }
    dfs1(1,0);dfs2(1,0);
    int las=0;
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        x^=las;int fa=lca(x,y);
        las=b[ask(rt[x],rt[y],rt[fa],rt[f[fa]],1,kkk,z)];
        cout<<las<<'\n';
    }
    return 0;
}
