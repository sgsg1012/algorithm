/* https://codeforces.com/contest/1620/problem/C */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
void solve()
{
    ll n,k,x;
    cin>>n>>k>>x;
    x=x-1;
    string s;cin>>s;
    vector<ll> bases;
    bool tag=true;
    ll num=k;
    for(ll i=n-1;i>=0;i--)
    {
        if(s[i]=='*')
        {
            if(!tag)
            {
                num+=k;
                continue;
            }
            if(bases.empty())
            {
                bases.push_back(1);
            }
            else 
            {
                bases.push_back((num+1));
            }
            num=k;
            tag=false;
        }
        else 
        {
            tag=true;
        }
    }
    vector<ll> arr;
    ll len=bases.size();
    for(ll i=1;i<=len;i++)
    {
        if(x==0) break;
        if(i==len)
        {
            arr.push_back(x);
            break;
        }
        arr.push_back(x%bases[i]);
        x/=bases[i];
    }
    string ans;
    ll idx=0;
    tag=true;
    ll arrSize=arr.size();
    ll i=n-1;
    for(;i>=0;i--)
    {
        if(s[i]=='a')
        {
            ans+=s[i];
            tag=true;
            continue;
        }
        if(tag)
        {
            if(idx>=arrSize) break;
            ll len=arr[idx];
            for(ll i=0;i<len;i++)
            {
                ans+='b';
            }
            tag=false;
            idx++;
        }
    }
    while(i>=0)
    {
        if(s[i]=='a')
        {
            ans+=s[i];
        }
        i--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
    // cout<<'a'*5<<endl;
    // system("pause");
    return 0;
}