/* 
    01背包
    链接：https://www.acwing.com/problem/content/2/

    0-1 背包 是较为简单的动态规划问题，也是其余背包问题的基础。
    动态规划是不断决策求最优解的过程，「0-1 背包」即是不断对第 i 个物品的做出决策，「0-1」正好代表不选与选两种决定。
    题解：https://www.acwing.com/solution/content/1374/
 */
/* 二维状态表示 */
#include <iostream>
using namespace std;
const int N = 1010;
struct bag
{
    int v;
    int w;
} bags[N];
int f[N][N];
int main()
{
    int n;
    int V;
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> bags[i].v >> bags[i].w;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            if (j < bags[i].v)
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = max(f[i - 1][j], f[i - 1][j - bags[i].v] + bags[i].w);
        }
    }
    cout << f[n][V] << endl;
    return 0;
}
/* 一维状态表示 
注意：
    遍历j时从大到小遍历

#include <iostream>
using namespace std;
const int N = 1010;
struct bag
{
    int v;
    int w;
} bags[N];
int f[N];
int main()
{
    int n;
    int V;
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> bags[i].v >> bags[i].w;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = V; j >= bags[i].v; j--)
        {
            f[j] = max(f[j], f[j - bags[i].v] + bags[i].w);
        }
    }
    cout << f[V] << endl;
    return 0;
}*/