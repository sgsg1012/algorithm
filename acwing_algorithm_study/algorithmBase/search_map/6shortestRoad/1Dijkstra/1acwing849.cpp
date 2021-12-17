/* 
https://www.acwing.com/problem/content/851/
思路：
    维护一个确定最短距离的集合
    每次在剩余的点中找到距离最小的那个点，进入集合
    用该点更新剩余点距离
    一直重复知道找到n
 */
#include <iostream>
#include <cstring>
using namespace std;
const int N = 510;
int g[N][N];
const int MAX = 1e9;
int n, m;
int dist[N];
bool st[N]; //表示是否已经确定最短路
int dijkstar()
{
    st[1] = true;
    for (int i = 0; i < N; i++)
    {
        dist[i] = 1e9;
    }
    dist[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = min(dist[1] + g[1][i], dist[i]);
    }
    while (true)
    {
        int m = 1e9, idx = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!st[i])
            {
                if (dist[i] < m)
                {
                    m = dist[i];
                    idx = i;
                }
            }
        }
        st[idx] = true;
        if (idx == n)
            return dist[n];
        for (int i = 1; i <= n; i++)
        {
            dist[i] = min(dist[idx] + g[idx][i], dist[i]);
        }
    }
}
int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            g[i][j] = MAX;
        }
    }
    cin >> n >> m;
    int a, b, w;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        g[a][b] = min(g[a][b], w);
    }
    cout << dijkstar() << endl;
    return 0;
}