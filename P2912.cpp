#include<bits/stdc++.h>
using namespace std;  
const int N=1002;
struct lfxxx{int nxt,o,z;}a[N<<1];
int n,m,k,h[N],top[N],siz[N],f[N],fat[N],high[N],s[N];
void add(int x,int y,int z){a[++k].nxt=y;a[k].z=z;a[k].o=h[x];h[x]=k;}
void dfs1(int x,int fa){
    high[x]=high[fa]+1;f[x]=fa;siz[x]=1;
    for(int i=h[x];i;i=a[i].o)
        if(a[i].nxt!=fa){
            int nx=a[i].nxt;
            s[nx]=s[x]+a[i].z;
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
        if(a[i].nxt!=fat[x]&&a[i].nxt!=f[x])
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
int ans(int x,int y){return s[x]+s[y]-(s[lca(x,y)]<<1);}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y,z;i<n;i++){
        cin>>x>>y>>z;
        add(x,y,z);add(y,x,z);
    }
    dfs1(1,1);dfs2(1,1);
    while(m--){
        int x,y;
        cin>>x>>y;
        cout<<ans(x,y)<<'\n';
    }
    return 0;
}