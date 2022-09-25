#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int ls[N<<5],rs[N<<5],s[N<<5],rt[N];
int n,m,k,cnt,a[N],b[N],cnm;
int clo(int x){
    cnt++;
    ls[cnt]=ls[x];rs[cnt]=rs[x];s[cnt]=s[x];
    return cnt;
}
int build(int l,int r,int x){
    x=++cnt;
    if(l==r)
        return x;
    int mid=((l+r)>>1);
    ls[x]=build(l,mid,0);
    rs[x]=build(mid+1,r,0);
    return x;
}
int update(int need,int l,int r,int x,int k){
    x=clo(x);
    if(l==r){
        s[x]+=k;
        return x;
    }
    int mid=((l+r)>>1);
    if(need<=mid)
        ls[x]=update(need,l,mid,ls[x],k);
    else
        rs[x]=update(need,mid+1,r,rs[x],k);
    s[x]=s[ls[x]]+s[rs[x]];
    return x;
}
int ask(int l,int r,int nowl,int nowr,int k){
    if(nowl==nowr)
        return b[nowl];
    int mid=((nowl+nowr)>>1),now=s[ls[r]]-s[ls[l]];
    if(now>=k)
        return ask(ls[l],ls[r],nowl,mid,k);
    else
        return ask(rs[l],rs[r],mid+1,nowr,k-now);
}
int find(int l,int r,int x){
    while(l<r){
        int mid=((l+r+1)>>1);
        if(b[mid]>x)
            r=mid-1;
        else
            l=mid;
    }
    return l;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1);
    int kkk=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++)
        a[i]=find(1,kkk,a[i]);
    rt[0]=build(1,n,0);
    for(int i=1;i<=n;i++)
        rt[i]=update(a[i],1,n,rt[i-1],1);
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        cout<<ask(rt[x-1],rt[y],1,n,z)<<'\n';
    }
    return 0;
}