#include<iostream>
using namespace std;
int a[7];
void solve()
{
    int n=7;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<a[0]<<" "<<a[1]<<" "<<a[6]-a[0]-a[1]<<endl;
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