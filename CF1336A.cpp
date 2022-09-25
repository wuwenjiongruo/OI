#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+2;
struct Graph{int nxt,o;}a[N<<1];
struct lfxxx{int h,siz;}ans[N];
int n,m,k,f[N];
void add(int x,int y){a[++k].nxt=y;a[k].o=f[x];f[x]=k;}
bool cmp(lfxxx o,lfxxx p){return o.h-o.siz>p.h-p.siz;}
void dfs(int x,int fa){
    ans[x].h=ans[fa].h+1;ans[x].siz=1;
    for(int i=f[x];i;i=a[i].o)
        if(a[i].nxt!=fa){
            int nx=a[i].nxt;
            dfs(nx,x);
            ans[x].siz+=ans[nx].siz;
        }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y;i<n;i++){
        cin>>x>>y;
        add(x,y);add(y,x);
    }
    dfs(1,1);
    sort(ans+1,ans+n+1,cmp);
    int s=0;
    for(int i=1;i<=m;i++)
        s+=ans[i].h-ans[i].siz;
    cout<<s;
    return 0;
}