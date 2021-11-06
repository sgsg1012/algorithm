#include <iostream>
using namespace std;
const int N = 55;
int a[N];
int b[N];
int f[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = 0;
            for (int k = i; k <= j; k++)
            {
                int num = b[k];
                if (num > j - i + 1)
                    continue;
                int my = j - k + 1;
                int ni, nj;
                if (num < my)
                {
                    ni = i;
                    nj = j;
                }
                else if (num == my)
                {
                    ni = i;
                    nj = k - 1;
                }
                else
                {
                    nj = k - 1;
                    ni = i + (num - my);
                }
                f[i][j] = max(f[i][j], f[ni][nj] + a[k]);
            }
        }
    }
    cout << f[1][n] << endl;
    system("pause");
    return 0;
}