#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2,M=1e6+2;
struct lfxxx{int nxt,o,z;}a[N<<1];
struct node{int w,s;}b[N];
int n,m,k,cnt,zhong,op,ans=INT_MAX;
int h[N],t[M],siz[N],fat[N];bool v[N];
void add(int x,int y,int z){a[++k].nxt=y;a[k].z=z;a[k].o=h[x];h[x]=k;}
void dfs1(int x,int fa){
    siz[x]=1;fat[x]=0;
    for(int i=h[x];i;i=a[i].o)
        if(a[i].nxt!=fa&&!v[a[i].nxt]){
            dfs1(a[i].nxt,x);
            siz[x]+=siz[a[i].nxt];
            fat[x]=max(fat[x],siz[a[i].nxt]);
        }
    fat[x]=max(fat[x],op-siz[x]);
    if(fat[x]<fat[zhong])
        zhong=x;
}
void dfs2(int x,int fa,int w,int s){
    if(w>m)
        return ;
    b[++cnt]=(node){w,s};
    for(int i=h[x];i;i=a[i].o)
        if(a[i].nxt!=fa&&!v[a[i].nxt])
            dfs2(a[i].nxt,x,w+a[i].z,s+1);
}
void answer(int x){
    t[0]=cnt=0;
    for(int i=h[x];i;i=a[i].o)
        if(!v[a[i].nxt]){
            int xx=cnt;
            dfs2(a[i].nxt,x,a[i].z,1);
            for(int j=xx+1;j<=cnt;j++)
                ans=min(ans,t[m-b[j].w]+b[j].s);
            // cout<<ans<<'\n';
            for(int j=xx+1;j<=cnt;j++)
                t[b[j].w]=min(t[b[j].w],b[j].s);
            // cout<<'\n';
        }
    for(int i=1;i<=cnt;i++)
        t[b[i].w]=INT_MAX;
}
void dfs(int x){
    v[x]=1;answer(x);
    for(int i=h[x];i;i=a[i].o)
        if(!v[a[i].nxt]){
            op=siz[a[i].nxt];zhong=0; 
            dfs1(a[i].nxt,x);
            dfs(zhong);
        }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;fat[0]=n+1;op=n;
    for(int i=1,x,y,z;i<n;i++){
        cin>>x>>y>>z;x++;y++;
        add(x,y,z);add(y,x,z);
    }
    dfs1(1,0);memset(t,0x7f,sizeof(t));
    dfs(zhong);
    if(ans>n)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}