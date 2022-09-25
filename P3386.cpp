#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2;
int n,m,e,match[N];bool v[N];
vector<int>G[N];
bool dfs(int x){
    for(int i=0;i<G[x].size();i++)
        if(!v[G[x][i]]){
            int nx=G[x][i];
            v[nx]=1;
            if(!match[nx]||dfs(match[nx])){
                match[nx]=x;
                return 1;
            }
        }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>e;
    for(int i=1,x,y;i<=e;i++){
        cin>>x>>y;
        G[x].push_back(y);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dfs(i))
            ans++;
        memset(v,0,sizeof(v));
    }
    cout<<ans;
    return 0;
}