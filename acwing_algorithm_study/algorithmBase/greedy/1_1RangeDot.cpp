/* 
区间选点：
    链接：https://www.acwing.com/problem/content/907/
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
struct Range
{
    int l, r;
    bool operator<(const Range &m)
    {
        return r < m.r;
    }
} range[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> range[i].l;
        cin >> range[i].r;
    }
    sort(range, range + n);
    // sort(range,range+n,[](Range & a,Range & b){return a.r<b.r;});
    int res = 0, ed = -2e9;
    for (int i = 0; i < n; i++)
    {
        if (range[i].l > ed)
        {
            res++;
            ed = range[i].r;
        }
    }
    cout << res << endl;
    return 0;
}