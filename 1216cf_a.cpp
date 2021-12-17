#include<iostream>
#include<algorithm>
using namespace std;
void solve()
{
    string s,p;
    cin>>s>>p;
    if(p=="abc") p="acb";
    else p="abc";
    // next_permutation(p.begin(),p.end());
    sort(s.begin(),s.end());
    if(p=="abc")
    {
        cout<<s<<endl;
        return ;
    }
    int a=0,b=0,c=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>'c') break;
        if(s[i]=='a') a++;
        else if(s[i]=='b') b++;
        else c++;
    }
    if(a==0||b==0||c==0)
    {
        cout<<s<<endl;
        return ;
    }
    string pres="";
    for(int i=0;i<3;i++)
    {
        if(p[i]=='a')
        {
            for(int i=0;i<a;i++) pres+='a';
        }
        else if(p[i]=='b')
        {
            for(int i=0;i<b;i++) pres+='b';
        }
        else 
        {
            for(int i=0;i<c;i++) pres+='c';
        }
    }
    for(int i=0;i<a+b+c;i++)
    {
        s[i]=pres[i];
    }
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