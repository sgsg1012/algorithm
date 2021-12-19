/* https://codeforces.com/contest/1591/problem/A */
#include<iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    while(n--)
    {
        int num;cin>>num;
        int height=1;
        int last=-1;
        int x;
        bool died=false;
        for(int i=0;i<num;i++)
        {
            cin>>x;
            if(x)
            {
                if(last==1) height+=5;
                else height+=1;
            }
            else 
            {
                if(last==0)
                {
                    died=true;
                }
            }
            last=x;
        }
        if(died) cout<<-1<<endl;
        else cout<<height<<endl;
    }
    return 0;
}