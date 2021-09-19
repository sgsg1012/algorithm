/* 题目链接：https://www.acwing.com/problem/content/799/ */
/* 前缀和的逆运算 */
#include <iostream>
using namespace std;
const int N = 100010;
int sum[N];

int q[N];

int main()
{
    int n, m;
    sum[0] = 0;
    q[0] = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> sum[i];
        q[i] = sum[i] - sum[i - 1];
    }
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        q[l] += c;
        q[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + q[i];
        cout << sum[i] << " ";
    }
    cout << endl;
    return 0;
}