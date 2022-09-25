#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n,m,a[N],ls[N],rs[N],p[N],f[N];bool dele[N];
void clear(int x){ls[x]=rs[x]=p[x]=0;}
int find(int x){
    if(f[x]==x)
        return x;
    return f[x]=find(f[x]);
}
int hb(int x,int y){
    if(!x||!y)
        return x+y;
    if(a[x]>a[y])
        swap(x,y);
    rs[x]=hb(rs[x],y);
    if(p[ls[x]]<p[rs[x]])
        swap(ls[x],rs[x]);
    p[x]=(!rs[x]?0:p[rs[x]]+1);
    return x;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],f[i]=i;
    while(m--){
        int op,x,y;
        cin>>op>>x;
        if(op==1){
            cin>>y;
            if(dele[x]||dele[y])
                continue;
            int fax=find(x),fay=find(y);
            if(fax!=fay)
                f[fax]=f[fay]=hb(fax,fay);
        }
        else if(dele[x])
            cout<<"-1\n";
        else{
            int fax=find(x);
            cout<<a[fax]<<'\n';dele[fax]=1;
            f[ls[fax]]=f[rs[fax]]=f[fax]=hb(ls[fax],rs[fax]);
            clear(fax);
        }
    }
    return 0;
}