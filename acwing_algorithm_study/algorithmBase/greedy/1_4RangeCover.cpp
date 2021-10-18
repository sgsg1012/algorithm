/* 
链接：https://www.acwing.com/problem/content/909/
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100100;
struct Range
{
    int l, r;
    bool operator<(const Range &a)
    {
        return l < a.l;
    }
} range[N];
int main()
{
    int s;
    int t;
    cin >> s >> t;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> range[i].l >> range[i].r;
    }
    sort(range, range + n);
    int r = s;
    int cnt = 1;
    for (int i = 0; i < n;)
    {
        if (range[i].l <= s)
        {
            r = max(r, range[i].r);
            i++;
        }
        else
        {
            if (r >= t)
                break;
            // cout<<r<<endl;
            if (s == r)
                break;
            cnt++;
            s = r;
            // cout<<s<<endl;
        }
    }
    if (r >= t)
        cout << cnt << endl;
    else
        cout << -1 << endl;
    return 0;
}