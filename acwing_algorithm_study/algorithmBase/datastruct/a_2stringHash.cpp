/* 
字符串哈希
    链接：https://www.acwing.com/problem/content/843/
 */
#include <iostream>
using namespace std;
const int p = 131;
typedef unsigned long long ull;
const int N = 100010;
ull a[N], pp[N];
char s[N];
int main()
{
    int n, m;
    cin >> n >> m;
    cin >> s + 1;
    pp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] * p + s[i];
        pp[i] = pp[i - 1] * p;
    }
    int l1, r1, l2, r2;
    while (m--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        ull x1 = a[r1] - a[l1 - 1] * pp[r1 - l1 + 1];
        ull x2 = a[r2] - a[l2 - 1] * pp[r2 - l2 + 1];
        if (x1 == x2)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
}