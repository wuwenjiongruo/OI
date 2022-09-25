#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+2,MAX=1e18;
struct lfxxx{int nxt,o,w;}a[N<<1];
int n,m,s,t,k=1,h[N],lev[N],now[N];
void add(int x,int y,int z){a[++k].nxt=y;a[k].w=z;a[k].o=h[x];h[x]=k;}
bool bfs(){
    queue<int>q;q.push(s);
    for(int i=1;i<=n;i++)
        lev[i]=0;
    lev[s]=1;
    while(!q.empty()){
        int xx=q.front();q.pop();
        for(int i=h[xx];i;i=a[i].o)
            if(a[i].w&&!lev[a[i].nxt])
                lev[a[i].nxt]=lev[xx]+1,q.push(a[i].nxt);
    }
    return lev[t];
}
int dfs(int x,int ss){
    if(x==t)
        return ss;
    for(int &i=now[x];i;i=a[i].o){
        int nx=a[i].nxt,z=a[i].w;
        if(z&&lev[nx]==lev[x]+1){
            int ns=dfs(nx,min(ss,z));
            if(ns){
                a[i].w-=ns;a[i^1].w+=ns;
                return ns;
            }
        }
    }
    return 0;
}
int maxflow(){
    int xx=0;
    while(bfs()){
        for(int i=1;i<=n;i++)
            now[i]=h[i];
        int op=dfs(s,MAX);xx+=op;
        while(op){
            op=dfs(s,MAX);
            xx+=op;
        }
    }
    return xx;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s>>t;
    for(int i=1,x,y,z;i<=m;i++){
        cin>>x>>y>>z;
        add(x,y,z);add(y,x,0);
    }
    cout<<maxflow();
    return 0;
}