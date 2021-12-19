/* https://codeforces.com/contest/1620/problem/A */
#include<iostream>
using namespace std;
void solve()
{
    string s;cin>>s;
    int len = s.size();
    int relation=1;
    for(int i=0;i<len-1;i++)
    {
        if(i==0)
        {
            if(s[i]=='E') relation=1;
            else relation=0;
            continue;
        }
        if(s[i]=='N')
        {
            if(relation==1)
            {
                relation=0;    
            }
            else 
            {
                relation=-1;
            }
        }
    }
    if(relation==-1) cout<<"YES"<<endl;
    else if(relation==0)
    {
        if(s[len-1]=='E') cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    else
    {
        if(s[len-1]=='N') cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
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