/* 
    石子合并 链接：https://www.acwing.com/problem/content/284/
    
    区间dp 
        就是把原来的f[i] 表示前i个物体(也就是1~j)怎么样
        改成了f[i][j] 表示i到j物体怎么样

    状态表示
        f[i][j] 
        集合：从i到j堆石头合成一堆所有方案
        属性：min
    状态计算
        考虑最后一次合并在哪一个位置，遍历所有位置找出min即可


 */
#include <iostream>
#include <vector>
using namespace std;
const int N = 310;
int a[N];
int f[N][N];
int sum[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i][i] = 0;
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            f[i][j] = 1e9;
            for (int k = i; k <= j - 1; k++)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
            }
            // cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
        }
    }
    cout << f[1][n] << endl;
    return 0;
}