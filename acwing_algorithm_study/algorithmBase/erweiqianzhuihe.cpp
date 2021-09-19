/* 题目链接：https://www.acwing.com/problem/content/798/ */
#include <iostream>
using namespace std;
const int N = 1100;
int mat[N][N];
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int tem;
            cin >> tem;
            mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1] + tem;
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << mat[x2][y2] - mat[x1 - 1][y2] - mat[x2][y1 - 1] + mat[x1 - 1][y1 - 1] << endl;
    }

    return 0;
}