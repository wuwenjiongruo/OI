#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,f[114514]={1,1};
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i]+=f[j-1]*f[i-j];
	cout<<f[n];
    return 0;
}