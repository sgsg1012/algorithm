/* 
 数字三角形 链接：https://www.acwing.com/problem/content/900/
  */
#include <iostream>
using namespace std;
const int N = 550;
int ang[N][N];
int f[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> ang[i][j];
            f[i][j] = -5e7;
        }
    }
    f[1][1] = ang[1][1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j > 1)
                f[i][j] = f[i - 1][j - 1];
            if (j < i)
                f[i][j] = max(f[i][j], f[i - 1][j]);
            f[i][j] += ang[i][j];
        }
    }
    int ans = f[n][1];
    for (int i = 2; i <= n; i++)
    {
        ans = max(ans, f[n][i]);
    }
    cout << ans << endl;
    return 0;
}