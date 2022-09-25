#include<bits/stdc++.h>
#define ls (x<<1)
#define rs (x<<1|1)
using namespace std;
const int N=5e4+2;
struct lfxxx{int l,r,x;}a[N];
int n,m,c,mx[N<<2],tag[N<<2];
bool cmp(lfxxx o,lfxxx p){return o.r<p.r;}
void push_up(int x){mx[x]=max(mx[ls],mx[rs]);}
void push_down(int x){
    if(!tag[x])
        return ;
    int now=tag[x];tag[x]=0;
    tag[ls]+=now;tag[rs]+=now;
    mx[ls]+=now;mx[rs]+=now;
}
void update(int l,int r,int nowl,int nowr,int x,int k){
    if(nowl>=l&&nowr<=r){
        mx[x]+=k;tag[x]+=k;
        return ;
    }
    push_down(x);
    int mid=((nowl+nowr)>>1);
    if(l<=mid)
        update(l,r,nowl,mid,ls,k);
    if(r>mid)
        update(l,r,mid+1,nowr,rs,k);
    push_up(x);
}
int ask(int l,int r,int nowl,int nowr,int x){
    if(nowl>=l&&nowr<=r)
        return mx[x];
    push_down(x);
    int mid=((nowl+nowr)>>1),xx=INT_MIN;
    if(l<=mid)
        xx=ask(l,r,nowl,mid,ls);
    if(r>mid)
        xx=max(xx,ask(l,r,mid+1,nowr,rs));
    return xx;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r>>a[i].x,a[i].r--;
    sort(a+1,a+n+1,cmp);
    int ans=0;
    for(int i=1;i<=n;i++){
        int now=min(c-ask(a[i].l,a[i].r,1,m,1),a[i].x);ans+=now;
        update(a[i].l,a[i].r,1,m,1,now);
    }
    cout<<ans;
    return 0;
}