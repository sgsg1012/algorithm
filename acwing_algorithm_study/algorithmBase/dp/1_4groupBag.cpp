/* 
分组背包 链接：https://www.acwing.com/problem/content/9/
    j>=v条件不要忘了
 */
#include <iostream>
using namespace std;
const int N = 110;
int v[N][N];
int w[N][N];
int f[N][N];
int main()
{
    int n;
    int V;
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        v[i][0] = num;
        for (int j = 1; j <= num; j++)
        {
            cin >> v[i][j] >> w[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            f[i][j] = f[i - 1][j];
            int num = v[i][0];
            for (int k = 1; k <= num; k++)
            {
                if (j >= v[i][k])
                    f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout << f[n][V] << endl;
    return 0;
}