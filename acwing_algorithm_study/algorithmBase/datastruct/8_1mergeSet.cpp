/* 
8_1 合并集合 链接：https://www.acwing.com/problem/content/838/
 */
#include <iostream>
using namespace std;
const int N = 100010;
int p[N];
int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int n;
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    while (m--)
    {
        char c;
        cin >> c;
        int x, y;
        cin >> x >> y;
        if (c == 'M')
        {
            int xr = find(x);
            int yr = find(y);
            p[xr] = yr;
        }
        else
        {
            if (find(x) == find(y))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}