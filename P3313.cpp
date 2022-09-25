#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+2;
struct lfxxx{int nxt,o;}a[N<<1];
int n,m,k,cnm,h[N],b[N],col[N];
int high[N],siz[N],fat[N],f[N],top[N],df[N];
void add(int x,int y){a[++k].nxt=y;a[k].o=h[x];h[x]=k;}
void dfs1(int x,int fa){
    f[x]=fa;high[x]=high[fa]+1;siz[x]=1;
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
    top[x]=topp;df[x]=++cnm;
    if(!fat[x])
        return ;
    dfs2(fat[x],topp);
    for(int i=h[x];i;i=a[i].o)
        if(a[i].nxt!=f[x]&&a[i].nxt!=fat[x])
            dfs2(a[i].nxt,a[i].nxt);
}
int cnt,ls[N*80],rs[N*80],s[N*80],mx[N*80],rt[N];
void push_up(int x){
    s[x]=s[ls[x]]+s[rs[x]];
    mx[x]=max(mx[ls[x]],mx[rs[x]]);
}
void update(int need,int l,int r,int &x,int k){
    if(!x)
        x=++cnt;
    if(l==r){
        mx[x]=s[x]=k;
        return ;
    }
    int mid=((l+r)>>1);
    if(need<=mid)
        update(need,l,mid,ls[x],k);
    else
        update(need,mid+1,r,rs[x],k);
    push_up(x);
}
void del(int need,int l,int r,int &x){
    if(l==r){
        s[x]=mx[x]=0;x=0;
        return ;
    }
    int mid=((l+r)>>1);
    if(need<=mid)
        del(need,l,mid,ls[x]);
    else
        del(need,mid+1,r,rs[x]);
    push_up(x);
    if(!ls[x]&&!rs[x])
        s[x]=mx[x]=0,x=0;
}
int ask_sum(int l,int r,int nowl,int nowr,int x){
    if(!x)
        return 0;
    if(nowl>=l&&nowr<=r)
        return s[x];
    int mid=((nowl+nowr)>>1),xx=0;
    if(l<=mid)
        xx=ask_sum(l,r,nowl,mid,ls[x]);
    if(r>mid)
        xx+=ask_sum(l,r,mid+1,nowr,rs[x]);
    return xx;
}
int ask_max(int l,int r,int nowl,int nowr,int x){
    if(!x)
        return 0;
    if(nowl>=l&&nowr<=r)
        return mx[x];
    int mid=((nowl+nowr)>>1),xx=LONG_LONG_MIN;
    if(l<=mid)
        xx=ask_max(l,r,nowl,mid,ls[x]);
    if(r>mid)
        xx=max(xx,ask_max(l,r,mid+1,nowr,rs[x]));
    return xx;
}
int query_sum(int x,int y,int kkk){
    int xx=0;
    while(top[x]!=top[y]){
        if(high[top[x]]<high[top[y]])
            swap(x,y);
        xx+=ask_sum(df[top[x]],df[x],1,n,rt[kkk]);
        x=f[top[x]];
    }
    if(high[x]<high[y])
        swap(x,y);
    return xx+ask_sum(df[y],df[x],1,n,rt[kkk]);
}
int query_max(int x,int y,int kkk){
    int xx=LONG_LONG_MIN;
    while(top[x]!=top[y]){
        if(high[top[x]]<high[top[y]])
            swap(x,y);
        xx=max(xx,ask_max(df[top[x]],df[x],1,n,rt[kkk]));
        x=f[top[x]];
    }
    if(high[x]<high[y])
        swap(x,y);
    return max(xx,ask_max(df[y],df[x],1,n,rt[kkk]));
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>b[i]>>col[i];
    for(int i=1,x,y;i<n;i++){
        cin>>x>>y;
        add(x,y);add(y,x);
    }
    dfs1(1,1);dfs2(1,1);
    for(int i=1;i<=n;i++)
        update(df[i],1,n,rt[col[i]],b[i]);
    while(m--){
        string c;int x,y;
        cin>>c>>x>>y;
        if(c[1]=='C'){
            del(df[x],1,n,rt[col[x]]);
            update(df[x],1,n,rt[y],b[x]);
            col[x]=y;
        }
        else if(c[0]=='C'){
            update(df[x],1,n,rt[col[x]],y);
            b[x]=y;
        }
        else if(c[1]=='S')
            cout<<query_sum(x,y,col[x])<<'\n';
        else
            cout<<query_max(x,y,col[x])<<'\n';
    }
    return 0;
}