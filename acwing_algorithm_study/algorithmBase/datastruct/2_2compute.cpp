/* 计算中序表达式的值
    题目链接：https://www.acwing.com/problem/content/3305/
 */
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
stack<int> d;
stack<char> op;
int priority(char c)
{

    if (c == '(')
        return 1;
    else if (c == '+' || c == '-')
        return 2;
    else
        return 3;
}
void compute()
{
    char c = op.top();
    int num1 = d.top();
    d.pop();
    int num2 = d.top();
    d.pop();
    int num = 0;
    if (c == '+')
        num = num2 + num1;
    else if (c == '-')
        num = num2 - num1;
    else if (c == '*')
        num = num2 * num1;
    else
        num = num2 / num1;
    d.push(num);
    op.pop();
}
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i])) //数字入栈
        {
            int x = 0, j = i; //计算数字
            while (j < s.size() && isdigit(s[j]))
            {
                x = x * 10 + (s[j] - '0');
                j++;
            }
            d.push(x); //数字入栈
            i = j - 1;
        }
        else if (s[i] == '(')
            op.push(s[i]);
        else if (s[i] == ')')
        {
            while (op.top() != '(')
            {
                compute();
            }
            op.pop();
        }
        else
        {
            char c = s[i];
            while (!op.empty() && priority(op.top()) >= priority(c))
            {
                compute();
            }
            op.push(c);
        }
    }
    while (!op.empty())
    {
        compute();
    }
    cout << d.top() << endl;
    return 0;
}