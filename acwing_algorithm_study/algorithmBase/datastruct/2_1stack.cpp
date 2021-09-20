/* 栈 
    链接：https://www.acwing.com/problem/content/830/
    数组模拟 top表示将要入栈元素的位置，也表示栈的长度
    每次入栈，top++，出栈 top--
 */
#include <iostream>
using namespace std;
const int N = 100010;
int st[N];
int top = 0;
void push(int x)
{
    st[top++] = x;
}
void pop()
{
    top--;
}
bool empty()
{
    return top == 0;
}
int query()
{
    return st[top - 1];
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
        {
            cout << query() << endl;
        }
    }
    return 0;
}