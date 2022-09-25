#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >p;
priority_queue<int>q;bool f[1000002];int s[1000002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int s1,s2;s1=s2=0;
    while(1){
        int op,x,y;
        cin>>op;
        if(op==1){
            cin>>x>>y;
            if(f[y])
                continue;
            s1+=x;s2+=y;f[y]=1;s[y]=x;
            q.push(y);p.push(y);
        }
        else if(op==2){
            while(!q.empty()&&!f[q.top()])
                q.pop();
            if(q.empty())
                continue;
            int now=q.top();q.pop();
            f[now]=0;s1-=s[now];s2-=now;s[now]=0;
        }
        else if(op==3){
            while(!p.empty()&&!f[p.top()])
                p.pop();
            if(p.empty())
                continue;
            int now=p.top();p.pop();
            f[now]=0;s1-=s[now];s2-=now;s[now]=0;
        }
        else
            break;
    }
    cout<<s1<<' '<<s2;
    return 0;
}