#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;cin>>n;
    while(n--)
    {
        int num;int k;
        vector<long long> pos;
        vector<long long> neg;
        cin>>num;cin>>k;
        for(int i=0;i<num;i++)
        {
            long long x;cin>>x;
            if(x<0) neg.push_back(-x);
            else if(x>0) pos.push_back(x);
        }
        sort(neg.begin(),neg.end(),[](int a,int b){return a>b;});
        sort(pos.begin(),pos.end(),[](int a,int b){return a>b;});
        vector<long long> dist;
        for(int i=0;i<neg.size();)
        {
            dist.push_back(neg[i]);
            i+=k;
        }
        for(int i=0;i<pos.size();)
        {
            dist.push_back(pos[i]);
            i+=k;
        }
        long long ans=0;
        long long mx=0;
        sort(dist.begin(),dist.end());
        int len=dist.size()-1;
        for(int i=0;i<len;i++)
        {
            ans+=dist[i]*2;
        }
        int idx=dist.size()-1;
        if(idx>=0) mx=dist[idx];
        ans+=mx;
        // if(dist.size()>0) ans+=dist[dist.size()-1];
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}