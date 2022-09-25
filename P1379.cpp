#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,-1,0};int dy[]={1,0,0,-1};
int b[5][5]={0,0,0,0,0,0,1,2,3,0,0,8,0,4,0,0,7,6,5,0,0,0,0,0,0};
struct lfxxx{
    int x[5][5];
    inline bool ch(){
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                if(x[i][j]!=b[i][j])
                    return 0;
        return 1;
    } 
    inline int guh(){
        int s=0;
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                s+=(x[i][j]!=b[i][j]);
        return s;
    }
}a;
string c;int xx,yy,l;
void dfs(lfxxx q,int x,int now,int xx,int yy,int s){
    if(now+q.guh()>x+1)
        return ;
    if(q.ch()){
        cout<<x-1;
        exit(0);
    }
    for(int i=0;i<4;i++){
        int nx=xx+dx[i],ny=yy+dy[i];
        if(nx>=1&&nx<=3&&ny>=1&&ny<=3&&i+s!=3){
            lfxxx op=q;
            swap(op.x[xx][yy],op.x[nx][ny]);
            dfs(op,x,now+1,nx,ny,i);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c;l=c.length();
    for(int i=0,x,y,s;i<l;i++){
        x=i/3+1;y=i%3+1;a.x[x][y]=c[i]-'0';
        if(c[i]-'0'==0)
            xx=x,yy=y;
    }
    if(a.ch()){
        cout<<0;
        return 0;
    }
    for(int i=0;;i++)
        dfs(a,i,1,xx,yy,-1);
    return 0;
}