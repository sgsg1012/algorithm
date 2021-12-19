/* https://www.acwing.com/problem/content/4202/ */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a,b;
vector<int> arr;
void solve()
{
    int l,r;cin>>l>>r;
    int ans=*(upper_bound(arr.begin(),arr.end(),r)-1);
    if(ans<l) cout<<-1<<endl;
    else cout<<ans<<endl;
}
int main()
{
    cin>>a>>b;
    for(int i=1;i*i<=a&&i*i<=b;i++)
    {
        if(a%i==0)
        {
            if(b%i==0) arr.push_back(i);
            if(b%(a/i)==0) arr.push_back(a/i);
        }
        if(b%i==0)
        {
            if(a%i==0) arr.push_back(i);
            if(a%(b/i)==0) arr.push_back(b/i);
        }
    }
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    int n;cin>>n;
    while(n--)
    {
        solve();
    }
    return 0;
}