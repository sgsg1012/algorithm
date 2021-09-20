/* 
区间合并 
链接：https://www.acwing.com/problem/content/805/
自定义sort lambda表达式
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
struct qujian
{
    int st;
    int ed;
} a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].st;
        cin >> a[i].ed;
    }
    sort(a, a + n, [](qujian b1, qujian b2)
         { return b1.st < b2.st; });
    int res = n;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i].ed >= a[i + 1].st)
        {
            a[i + 1].ed = max(a[i].ed, a[i + 1].ed);
            res--;
        }
    }
    cout << res << endl;
    return 0;
}
