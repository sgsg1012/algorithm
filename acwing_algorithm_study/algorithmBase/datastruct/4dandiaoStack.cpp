/* 
单调栈
链接：https://www.acwing.com/problem/content/832/
主要还是看想不想得到吧 思维难度较大
若是知道他是单调栈 那好做了 关键就是有时候想不到
 */
#include <iostream>
using namespace std;
const int N = 100010;
int stk[N];
int a[N];
int top = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        while (top != 0 && stk[top - 1] >= a[i])
        {
            top--;
        }
        if (top == 0)
        {
            stk[top++] = a[i];
            a[i] = -1;
        }
        else
        {
            int tem = stk[top - 1];
            stk[top++] = a[i];
            a[i] = tem;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}