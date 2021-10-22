/* 
    最短编辑距离 链接：https://www.acwing.com/problem/content/904/
    状态表示 f[i][j] 
        集合：表示使得a[1~i]变成b[1~j]的所有方案数
        属性：min
    状态转移
        考虑状态是怎么转移过来的就行
        状态转移嘛 老搜索算法了。。。。

        下面是大佬的题解,说的非常好
        """
        有三种操作，所以有三个子集
        ok子集划分完了
        考虑状态转移的时候
        先考虑如果我没有进行这个操作应该是什么状态
        然后考虑你进行这一步操作之后会对你下一个状态造成什么影响
        然后再加上之前状态表示中你决策出来的那个DP属性
        这样就可以自然而然地搞出来转移方程啦

        1)删除操作：把a[i]删掉之后a[1~i]和b[1~j]匹配
                    所以之前要先做到a[1~(i-1)]和b[1~j]匹配
                    f[i-1][j] + 1
        2)插入操作：插入之后a[i]与b[j]完全匹配，所以插入的就是b[j] 
                    那填之前a[1~i]和b[1~(j-1)]匹配
                    f[i][j-1] + 1 
        3)替换操作：把a[i]改成b[j]之后想要a[1~i]与b[1~j]匹配 
                    那么修改这一位之前，a[1~(i-1)]应该与b[1~(j-1)]匹配
                    f[i-1][j-1] + 1
                    但是如果本来a[i]与b[j]这一位上就相等，那么不用改，即
                    f[i-1][j-1] + 0

        好的那么f[i][j]就由以上三个可能状态转移过来，取个min

        """

        初始化
            一般只需要考虑f[0][0] f[i][0] f[0][j] 

 */
#include <iostream>
using namespace std;
const int N = 1100;
int f[N][N];
int main()
{
    int n;
    int m;
    string a, b;
    cin >> n;
    cin >> a;
    cin >> m;
    cin >> b;
    a = " " + a;
    b = " " + b;
    for (int i = 0; i <= n; i++)
        f[i][0] = i;
    for (int j = 0; j <= m; j++)
        f[0][j] = j;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i][j - 1] + 1, f[i - 1][j] + 1);
            if (a[i] == b[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}