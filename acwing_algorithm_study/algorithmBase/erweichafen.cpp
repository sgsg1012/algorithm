/* 题目链接：https://www.acwing.com/problem/content/800/ */
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1100;
int cha[N][N];
int sum[N][N];
int main()
{
    memset(cha, 0, sizeof(cha));
    memset(sum, 0, sizeof(sum));
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> sum[i][j];
            cha[i][j] = sum[i][j] + sum[i - 1][j - 1] - sum[i][j - 1] - sum[i - 1][j];
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        cha[x1][y1] += c;
        cha[x1][y2 + 1] -= c;
        cha[x2 + 1][y1] -= c;
        cha[x2 + 1][y2 + 1] += c;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + cha[i][j];
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}