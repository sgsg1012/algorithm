#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    int x=min(a,b);
    int y=max(a,b);
    while(y%x)
    {
        int tem=x;
        x=y%x;
        y=tem;
    }
    return x;
}
void solve()
{
    int n;cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(gcd(i,n-i-1)==1)
        {
            cout<<i<<" "<<n-i-1<<" "<<1<<endl;
            return ;
        }
    }

}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
    system("pause");
    return 0;
}