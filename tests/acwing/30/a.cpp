/* https://www.acwing.com/problem/content/4200/ */
#include<iostream>
using namespace std;
int main()
{
    int n,h;cin>>n>>h;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        if(a>h) ans+=2;
        else ans++;
    }
    cout<<ans<<endl;
    
    
    return 0;
}