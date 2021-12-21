/* https://codeforces.com/contest/1619/problem/E */
#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int pre[N];
long long ans[N];
int stk[N];
int top;
void solve()
{
    top=0;
    int n;cin>>n;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        m[x]++;
    }
    for(int i=0;i<n;i++)
    {
        if(i==0) pre[i]=m[i];
        else pre[i]=pre[i-1]+m[i];
    }
    ans[0]=m[0];
    cout<<ans[0]<<" ";
    if(m[0]>=2) stk[top++]=0;
    for(int i=1;i<=n;i++)
    {
        if(ans[i-1]==-1||pre[i-1]<i)
        {
            ans[i]=-1;
            cout<<ans[i]<<" ";
            continue;
        }
        ans[i]=ans[i-1]+m[i]-m[i-1];
        if(m[i-1]==0)
        {
            int k=stk[top-1];
            m[k]--;
            if(m[k]<2) top--;
            m[i-1]++;
            ans[i]+=i-1-k;
        }
        if(m[i]>=2) stk[top++]=i;
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}