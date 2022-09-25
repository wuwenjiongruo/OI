#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
struct lfxxx{int op,t,l,r;}b[N];
struct node{int p,x,y;}c[N];
int n,m,s,cnt,cnm=1,a[N],k[N],id[N],ans[N],v[N];
bool cmp(lfxxx x,lfxxx y){
    if(id[x.l]==id[y.l]){
        if(id[x.r]==id[y.r])
            return x.t<y.t;
        return id[x.r]<id[y.r];
    }
    return id[x.l]<id[y.l];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int size=(int)(pow(n,2.0/3));
	for(int i=1;i<=n;i++){
		cin>>a[i];
        id[i]=i/size;
    }
	memcpy(v,a,sizeof(v));
	for(int i=1;i<=m;i++){
		char op;int l,r;
		cin>>op>>l>>r;
		if(op=='R'){
            c[cnm++]=(node){l,v[l],r};
            v[l]=r;
        }
		else
            b[++cnt]=(lfxxx){cnt,cnm,l,r};
	}
	sort(b+1,b+cnt+1,cmp);
	int l=0,r=0,now=1;
	for(int i=1;i<=cnt;i++){
		while(now<b[i].t){
			if(l<=c[now].p&&c[now].p<=r)
                if((k[a[c[now].p]]--)==1)
                    s--;
			a[c[now].p]=c[now].y;
			if(l<=c[now].p&&c[now].p<=r)
                if(!(k[a[c[now].p]]++))
                    s++;
			now++;
		}
		while(now>b[i].t){
			now--;
			if(l<=c[now].p&&c[now].p<=r)
                if((k[a[c[now].p]]--)==1)
                    s--;
			a[c[now].p]=c[now].x;
			if(l<=c[now].p&&c[now].p<=r)
                if(!(k[a[c[now].p]]++))
                    s++;
		}
		while(l<b[i].l)
            if((k[a[l++]]--)==1)
                s--;
		while(l>b[i].l)
            if(!(k[a[--l]]++))
                   s++;
		while(r<b[i].r)
            if(!(k[a[++r]]++))
                s++;
		while(r>b[i].r)
            if((k[a[r--]]--)==1)
                s--;
		ans[b[i].op]=s;
	}
	for(int i=1;i<=cnt;i++)
		cout<<ans[i]<<'\n';
	return 0;
}