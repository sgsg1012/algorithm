#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int y;
    int r;
};
const int N = 100100;
node a[N];
int s[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].y >> a[i].r;
    }
    sort(a + 1, a + n + 1, [](node a, node b)
         { return a.y < b.y; });
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i].r;
    }
    int M = -1;
    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        int x1 = i - 1 - s[i - 1];
        int x2 = s[n] - s[i - 1];
        if (M <= x1 + x2)
        {
            M = x1 + x2;
            res = a[i].y;
        }
        while (i + 1 <= n && a[i + 1].y == a[i].y)
            i++;
    }
    cout << res << endl;
    return 0;
}