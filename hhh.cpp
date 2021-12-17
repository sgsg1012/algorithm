#include<iostream>
using namespace std;
const int N = 200010;
int a[N];
int front[N];
int back[N];
int main()
{
    int n;cin>>n;
    while(n--)
    {
        int num;cin>>num;
        int mx=0;
        for(int i=0;i<num;i++)
        {
            cin>>a[i];
            mx=max(mx,a[i]);
        }
        int ans=0;
        int tag=num-1;
        while(a[tag]!=mx)
        {
            for(int i=tag-1;i>=0;i--)
            {
                if(a[i]>a[tag])
                {
                    tag=i;
                    break;
                }
            }
            ans++;
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}