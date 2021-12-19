/* https://codeforces.com/contest/1620/problem/B */
#include<iostream>
using namespace std;
typedef long long ll;
void solve()
{
    ll w,h;cin>>w>>h;
    ll ans=0;
    for(int i=1;i<=4;i++)
    {
        int n;cin>>n;
        ll mn,mx;
        ll x;
        cin>>x;
        mn=mx=x;
        for(int i=1;i<n;i++)
        {
            cin>>x;
            mn=min(mn,x);
            mx=max(mx,x);
        }
        if(i==1||i==2)
        {
            ans=max(ans,(mx-mn)*h);
        }
        else
        {
            ans=max(ans,(mx-mn)*w);
        }
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