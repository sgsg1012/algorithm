/* 
多重背包 
1 朴素做法 链接：https://www.acwing.com/problem/content/4/
2 优化做法 链接：https://www.acwing.com/problem/content/5/
 */

/*  朴素做法 
#include <iostream>
using namespace std;
const int N = 110;
int v[N];
int w[N];
int s[N];
int f[N][N];
int main()
{
    int n;
    int V;
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            //朴素做法 n*n*n
            for (int k = 0; k * v[i] <= j && k <= s[i]; k++)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + k * w[i]);
            }
        }
    }
    cout << f[n][V] << endl;
    return 0;
} */
/* 二进制优化 
    原理：对于数字n，我们可以使用logn个01字符串表示n，也就是二进制表示
    这样就可以把多重背包转换成01背包，时间复杂度由n*n*n转为n*n*logn
    tql

    这个一定要进行内存优化，不然会超内存的 淦
*/
#include <iostream>
using namespace std;
const int N = 15000;
int v[N], w[N];
int f[2020];
int main()
{
    int n;
    int V;
    cin >> n >> V;
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int k = 1;
        while (c >= k)
        {
            v[cnt] = a * k;
            w[cnt] = b * k;
            cnt++;
            c -= k;
            k *= 2;
        }
        if (c > 0)
        {
            v[cnt] = a * c;
            w[cnt] = b * c;
            cnt++;
        }
    }
    for (int i = 1; i < cnt; i++)
    {
        for (int j = V; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[V] << endl;
    return 0;
}