#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
long long myfind(vector<long long> a)
{
    int len =a.size();
    long long mn=1e18+1;
    int mnidx=0;
    while(1)
    {
        int idx=0;
        for(int i=0;i<len;i++)
        {
            if(a[i]!=0) 
            {
                if(a[i]<mn)
                {
                    mn=a[i];
                    mnidx=i;
                }
                idx++;
            }
        }
        for(int i=0;i<len;i++)
        {
            if(i!=mnidx) a[i]%=mn;
        }
        if(idx==1) break;
    }
    return mn;
}
void solve()
{
    int n;cin>>n;
    vector<long long> a,b;
    for(int i=0;i<n;i++)
    {
        long long x;cin>>x;
        if(i%2)
        {
            a.push_back(x);
        }
        else b.push_back(x);
    }
    long long ax=myfind(a);
    long long bx=myfind(b);
    if(ax!=1)
    {
        bool tag=true;
        int len=b.size();
        for(int i=0;i<len;i++)
        {
            if(b[i]%ax==0)
            {
                tag=false;
                break;
            }
        }
        if(tag)
        {
            cout<<ax<<endl;
            return;
        }
    }
    if(bx!=1)
    {
        bool tag=true;
        int len=a.size();
        for(int i=0;i<len;i++)
        {
            if(a[i]%bx==0)
            {
                tag=false;
                break;
            }
        }
        if(tag)
        {
            cout<<bx<<endl;
            return;
        }
    }
    cout<<0<<endl;
    
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
//ac
int len=a.size();
for(int i=0;i<len-1;i++)
{
    //代码
}
//re
for(int i=0;i<a.size()-1;i++)
{
    //代码
}