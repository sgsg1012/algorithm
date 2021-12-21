/* https://codeforces.com/contest/1619/problem/A */
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string s;cin>>s;
    int len=s.size();
    if(len%2==1)
    {
        cout<<"NO"<<endl;
        return ;
    }
    for(int i=0;i<len/2;i++)
    {
        int j=i+len/2;
        if(s[i]!=s[j])
        {
            cout<<"NO"<<endl;
            return ;
        }
    }
    cout<<"YES"<<endl;
    return;
    
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