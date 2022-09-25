#include<bits/stdc++.h>
using namespace std;
int n,p,fac[20000530];
signed main(){
	scanf("%d%d",&n,&p);
	printf("%d\n",fac[1]=1);
	for(int i=2;i<=n;i++){
		fac[i]=1ll*fac[p%i]*(p-p/i)%p;
		printf("%d\n",fac[i]);
	}
	return 0;
}