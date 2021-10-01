/* 
区间分组：
    链接：https://www.acwing.com/problem/content/908/
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100010;
struct Range
{
    int l, r;
    bool operator<(const Range &m)
    {
        return l < m.l;
    }
} range[N];
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> range[0].l >> range[0].r;
    }
    sort(range, range + n);
    int mi = range[0].r;
    for (int i = 1; i < n; i++)
    {
        if (mi >= range[i].l)
            ans++;
        mi = min(mi, range[i].r);
    }
    cout << ans << endl;
    return 0;
}