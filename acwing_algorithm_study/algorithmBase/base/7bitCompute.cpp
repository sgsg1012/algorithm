/* 
位运算：
题目链接：https://www.acwing.com/problem/content/803/


求n的第k位数字: n >> k & 1
返回n的最后一位1：lowbit(n) = n & -n
 */
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int res = 0;
        while (x)
        {
            int j = x & -x;
            x -= j;
            res++;
        }
        cout << res << " ";
    }
    return 0;
}