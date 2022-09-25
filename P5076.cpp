#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+2;
int n,cnt,g,ls[N],rs[N],a[N],lev[N],siz[N],s[N];
void push_up(int x){siz[x]=siz[ls[x]]+siz[rs[x]]+s[x];}
void add(int x){a[++cnt]=x;lev[cnt]=rand();siz[cnt]=s[cnt]=1;}
void rotate(int &now,bool f){
    int x;
    if(!f){
        x=rs[now];rs[now]=ls[x];
        ls[x]=now;push_up(ls[now=x]);
    }
    else{
        x=ls[now];ls[now]=rs[x];
        rs[x]=now;push_up(rs[now=x]);
    }
    push_up(now);
}
void update(int &now,int k){
    if(!now){
        add(k);now=cnt;
        return ;
    }
    if(k==a[now])
        s[now]++;
    else if(k<a[now]){
        update(ls[now],k);
        if(lev[now]<lev[ls[now]])
            rotate(now,1);
    }
    else{
        update(rs[now],k);
        if(lev[now]<lev[rs[now]])
            rotate(now,0);
    }
    push_up(now);
}
int _rank(int now,int k){
    if(!now)
        return 0;
    if(k==a[now])
        return siz[ls[now]]+1;
    int xx;
    if(k<a[now])
        xx=_rank(ls[now],k);
    else
        xx=_rank(rs[now],k)+s[now]+siz[ls[now]];
    return xx;
}
int ask(int now,int k){
    if(!now)
        return INT_MAX;
    if(k<=siz[ls[now]])
        return ask(ls[now],k);
    else if(k-s[now]<=siz[ls[now]])
        return a[now];
    else
        return ask(rs[now],k-siz[ls[now]]-s[now]);
}
int ask_front(int now,int x){
    int front=-2147483647;
    while(now)
        if(x<=a[now])
            now=ls[now];
        else
            front=a[now],now=rs[now];
    return front;
}
int ask_back(int now,int x){
    int back=2147483647;
    while(now)
        if(x<a[now])
            back=a[now],now=ls[now];
        else
            now=rs[now];
    return back;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    add(INT_MIN);add(INT_MAX);
    g=1;rs[1]=2;push_up(g);
    cin>>n;
    while(n--){
        int op,x;
        cin>>op>>x;
        if(op==5)
            update(g,x);
        else if(op==1)
            cout<<_rank(g,x)-1<<'\n';
        else if(op==2)
            cout<<ask(g,x+1)<<'\n';
        else if(op==3)
            cout<<ask_front(g,x)<<'\n';
        else
            cout<<ask_back(g,x)<<'\n';
    }
    return 0;
}