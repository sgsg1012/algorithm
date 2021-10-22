/* 
最长公共子序列  链接：https://www.acwing.com/problem/content/899/
    
    dp
    状态表示 lon[i][j] 
        集合：所有在第一个序列的前i个字母中出现，且在第二个序列中前j个字母中出现的子序列集合
        属性：max(len)
    状态转移
        分为四种子状态：
            00 01 10 11
            分别表示a[i],b[j]在不在最长公共子序列中
        00计算：lon[i-1][j-1]
        11计算: lon[i-1][j-1]+1  //有条件的

        01和10：lon[i-1][j] lon[i][j-1]
        但是注意 01和10的表示并不准确
        lon[i-1][j]指的是a[i]不在公共子序列中，但是并不能保证b[j]在公共子序列中    
        lon[i][j-1]同理

        但是lon[i-1][j]包含01,且包含于lon[i][j]
        所以使用他们不会影响结果，我们做不到不重，但对于本题，做到不漏就可以了
        同时 00 状态也不需要计算了，因为包含在lon[i][j-1]中了
 */
#include <iostream>
using namespace std;
const int N = 1100;
int lon[N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            lon[i][j] = max(lon[i - 1][j], lon[i][j - 1]);
            if (a[i] == b[j])
                lon[i][j] = max(lon[i][j], lon[i - 1][j - 1] + 1);
        }
    }
    cout << lon[n][m] << endl;
    return 0;
}