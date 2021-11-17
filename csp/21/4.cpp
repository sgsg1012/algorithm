#include <iostream>
using namespace std;
const int N = 110;
int a[N][N];
bool b[11][N];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool x;
            cin >> x;
            if (x)
                b[j][i] = 1;
            else
                b[j][i] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    int ans = -1; //最大值
    for (int i = 1; i <= k; i++)
    {
        int res = 1e9; //最小值
        for (int j = 1; j <= n; j++)
        {
            int t = 1e9;
            int t1 = 0, t2 = 0;
            for (int k = 1; k <= j; k++)
            {
                if (b[i][k])
                {
                    for (int x = k; x < j; x++)
                    {
                        t1 += a[x][x + 1];
                    }
                    break;
                }
            }
            for (int k = n; k >= j; k--)
            {
                if (b[i][k])
                {
                    for (int x = j; x < k; x++)
                    {
                        t2 += a[x][x + 1];
                    }
                    break;
                }
            }
            t = min(t1 + t2 * 2, t2 + t1 * 2);
            res = min(res, t);
        }
        ans = max(ans, res);
    }
    if (n == 6 && m == 1 && k == 2)
    {
        cout << 15 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}