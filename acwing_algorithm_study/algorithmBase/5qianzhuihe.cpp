/* 简单 */
/* 题目链接：https://www.acwing.com/problem/content/797/ */
#include <iostream>
using namespace std;
#include <cstring>
const int N = 100010;
int seq[N];
int sum[N];
int main()
{
    int n, k;
    cin >> n >> k;
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++)
    {
        int tem;
        cin >> tem;
        sum[i] = sum[i - 1] + tem;
    }
    while (k--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}