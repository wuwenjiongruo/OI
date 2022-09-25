#include<bits/stdc++.h>
using namespace std;
int dx[]={1,1,2,2,-1,-1,-2,-2};int dy[]={2,-2,1,-1,2,-2,1,-1};
int b[7][7]={
    0,0,0,0,0,0,0,
    0,1,1,1,1,1,0,
    0,0,1,1,1,1,0,
    0,0,0,2,1,1,0,
    0,0,0,0,0,1,0,
    0,0,0,0,0,0,0,
    0,0,0,0,0,0,0};
struct lfxxx{
    int x[7][7];
    inline bool ch(){
        for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++)
                if(x[i][j]!=b[i][j])
                    return 0;
        return 1;
    } 
    inline int guh(){
        int s=0;
        for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++)
                if(x[i][j]!=b[i][j]&&x[i][j]!=2)
                    s++;
        return s;
    }
}a;
int xx,yy;bool ans;
void dfs(lfxxx q,int x,int now,int xx,int yy){
    if(now+q.guh()>x+1)
        return ;
    if(q.ch()){
        ans=1;
        return ;
    }
    for(int i=0;i<8;i++){
        int nx=xx+dx[i],ny=yy+dy[i];
        if(nx>=1&&nx<=5&&ny>=1&&ny<=5){
            lfxxx op=q;
            swap(op.x[xx][yy],op.x[nx][ny]);
            dfs(op,x,now+1,nx,ny);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        char c;
        for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++){
                cin>>c;
                if(c=='*')
                    xx=i,yy=j,a.x[i][j]=2;
                else
                    a.x[i][j]=c-'0';
            }
        for(int i=0;i<=15;i++){
            ans=0;
            dfs(a,i,1,xx,yy);
            if(ans){
                cout<<i<<'\n';
                goto here;
            }
        }
        cout<<"-1\n";here:;
    }
    return 0;
}