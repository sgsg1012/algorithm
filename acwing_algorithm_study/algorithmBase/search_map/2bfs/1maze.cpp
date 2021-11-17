/* 
https://www.acwing.com/problem/content/846/
 */
#include <iostream>
#include <queue>
using namespace std;
const int N = 110;
int n, m;
bool a[N][N];
bool st[N][N];
int bfs()
{
    queue<pair<int, int>> q;
    q.push(pair<int, int>(1, 1));
    int num = 0;
    st[1][1] = true;
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    while (q.size())
    {
        num++;
        int len = q.size();
        while (len--)
        {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = t.first + dx[i];
                int ny = t.second + dy[i];
                if (nx == n && ny == m)
                    return num;
                if (!(a[nx][ny] || st[nx][ny]))
                {
                    st[nx][ny] = true;
                    q.push(pair<int, int>(nx, ny));
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << bfs() << endl;
    return 0;
}
