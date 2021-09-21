/* 
    kmp 链接：https://www.acwing.com/problem/content/833/
 */
#include <iostream>
using namespace std;
const int N = 100010;
int ne[N];
char s[N], p[N * 10];
int main()
{
    int n;
    int m;
    cin >> n >> s + 1 >> m >> p + 1;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && s[j + 1] != s[i])
            j = ne[j];
        if (s[j + 1] == s[i])
            j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[j + 1] != p[i])
            j = ne[j];
        if (s[j + 1] == p[i])
            j++;
        if (j == n)
        {
            cout << i - n << " ";
            j = ne[j];
        }
    }
    return 0;
}