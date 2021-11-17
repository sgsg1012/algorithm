#include <iostream>
using namespace std;
int n, l, r, t;
const int N = 660;
int a[N][N];
int sum[N][N];
int main()
{
    cin >> n >> l >> r >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int Mni = min(i + r, n), Mnj = min(j + r, n);
            int mni = max(1, i - r), mnj = max(1, j - r);
            int s = sum[Mni][Mnj] - sum[mni - 1][Mnj] - sum[Mni][mnj - 1] + sum[mni - 1][mnj - 1];
            if (s <= t * (Mni - mni + 1) * (Mnj - mnj + 1))
                num++;
        }
    }
    cout << num << endl;
    return 0;
}