/* 
n-皇后
    链接：https://www.acwing.com/problem/content/845/
 */
#include <iostream>
using namespace std;
const int N = 10;
char a[N][N];
int n;
bool col[N];
bool add[N * 2];
bool sub[N * 2];
void dfs(int cnt)
{
    if (cnt >= n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!(col[i] || add[i + cnt + 1] || sub[cnt + 1 - i + n]))
        {
            col[i] = true;
            add[i + cnt + 1] = true;
            sub[cnt + 1 - i + n] = true;
            a[cnt + 1][i] = 'Q';
            dfs(cnt + 1);
            col[i] = false;
            add[i + cnt + 1] = false;
            sub[cnt + 1 - i + n] = false;
            a[cnt + 1][i] = '.';
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            a[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}