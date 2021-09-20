/* 
模拟队列 链接：https://www.acwing.com/problem/content/831/
    我是当h=t时表示队列为空，t表示队列最后一个元素的下一个位置 初始化h=t=0
    y总是h>t时表示队列为空 初始化 h=0 t=-1、
    应该都行吧
 */
#include <iostream>
using namespace std;
const int N = 100010;
int deq[N];
int h = 0;
int t = 0;
void push(int x)
{
    deq[t++] = x;
}
void pop()
{
    h++;
}
bool empty()
{
    return h == t;
}
int query()
{
    if (!empty())
    {
        return deq[h];
    }
    else
        cout << "队列是空的" << endl;
}
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        else if (s == "pop")
        {
            pop();
        }
        else if (s == "empty")
        {
            if (empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << query() << endl;
    }
    return 0;
}