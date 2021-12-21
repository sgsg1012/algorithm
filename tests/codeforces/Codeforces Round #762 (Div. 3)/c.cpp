/* https://codeforces.com/contest/1619/problem/C */
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long a,b,s;
    cin>>a>>s;
    b=0;
    long long idx=1;
    while(a&&s)
    {
        long long sum=s%10;
        long long aa=a%10;
        if(sum<aa)
        {
            s/=10;
            sum=sum+(s%10)*10;
        }
        if(sum-aa>=10||sum-aa<0)
        {
            cout<<-1<<endl;
            return ;
        }
        b=(sum-aa)*idx+b;
        idx=idx*10;
        s/=10;
        a/=10;
    }
    if(a!=0)
    {
        cout<<-1<<endl;
        return ;
    }
    if(s!=0)
    {
        b+=s*idx;
    }
    if(b==0)
    {
        cout<<-1<<endl;
        return ;
    }
    cout<<b<<endl;    
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