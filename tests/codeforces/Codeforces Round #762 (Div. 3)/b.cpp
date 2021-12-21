/* https://codeforces.com/contest/1619/problem/B */
#include<bits/stdc++.h>
using namespace std;
const int INI = 1000000000;
void solve()
{
    int n;cin>>n;
    int ans=sqrt(n);
    for(int i=1;i*i*i<=n;i++)
    {
        int x=i*i*i;
        int sx=sqrt(x);
        if(sx*sx==x) continue;
        ans++;
    }
    cout<<ans<<endl;
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