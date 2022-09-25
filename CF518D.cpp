#include<bits/stdc++.h>
using namespace std;
long double dp[2002][2002];
int main(){
    int n,t;long double p;
    cin>>n>>p>>t;
    scanf("%d%Lf%d",&n,&p,&t);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=t;j++)
            dp[i][j]=dp[i][j-1]*(1.0-p)*1.0+(dp[i-1][j-1]+1.0)*p*1.0;
    printf("%.12Lf",dp[n][t]);
    return 0;
}