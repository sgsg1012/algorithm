/* https://www.acwing.com/problem/content/4201/ */
/*  括号匹配
    没做出来 ┭┮﹏┭┮
 */
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int maxLen=0;
    int num=1;
    stack<int> stk;
    for(int i=0;i<n;i++)
    {
        if(stk.size()&&s[i]==')'&&s[stk.top()]=='(') stk.pop();
        else stk.push(i);
        int len =0;
        if(stk.size()) len=i-stk.top();
        else len=i+1;
        if(len>0&&len==maxLen) num++;
        else if(len>maxLen)
        {
            maxLen=len;
            num=1;
        }
    }
    cout<<maxLen<<" "<<num<<endl;
    
    return 0;
}