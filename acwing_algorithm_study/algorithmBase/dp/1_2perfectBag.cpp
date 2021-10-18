/* 
完全背包 
链接：https://www.acwing.com/problem/content/3/

    注意完全背包的优化
    不优化会tle

    一维的优化和01背包稍有不同，j要从前往后遍历
 */
#include <iostream>
using namespace std;
const int N = 1010;
int v[N];
int w[N];
int f[N][N];
int main()
{
    int n;
    int V;
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            /* 朴素做法 tle
            for (int k = 0; k * v[i] <= j; k++)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + k * w[i]);
            } */
            /* 优化 */
            if (j >= v[i])
                f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]);
            else
                f[i][j] = f[i - 1][j];
        }
    }
    cout << f[n][V] << endl;
    return 0;
}