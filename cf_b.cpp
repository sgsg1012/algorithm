#include<iostream>
#include<vector>
using namespace std;
void solve()
{
    vector<string> arr;
    int num;cin>>num;
    for(int i=0;i<num-2;i++)
    {
        string s;cin>>s;
        arr.push_back(s);
    }
    string s=arr[0];
    for(int i=1;i<num-2;i++)
    {
        if(s.back()==arr[i].front())
        {
            s+=arr[i][1];
        }
        else s+=arr[i];
    }
    while(s.size()<num) s+='a';
    cout<<s<<endl;
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