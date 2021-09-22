/* 
连通块中点的数量 链接：https://www.acwing.com/problem/content/839/
思路一样 只是维护一个cnt[]记录元素的个数 
但是注意一点 ：
    如果x,y是同一个集合里的 那就不要再加个数了
 if (xr == yr)
    continue; //!!!!!!!!!!!!!!!!!!
 */
#include <iostream>
using namespace std;
const int N = 100010;
int p[N];
int cnt[N];
int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        cnt[i] = 1;
    }
    char c;
    while (m--)
    {
        cin >> c;
        if (c == 'C')
        {
            int x, y;
            cin >> x >> y;
            int xr = find(x);
            int yr = find(y);
            if (xr == yr)
                continue; //!!!!!!!!!!!!!!!!!!
            p[xr] = yr;
            cnt[yr] += cnt[xr];
        }
        else if (c == 'Q1')
        {
            int x, y;
            cin >> x >> y;
            int xr = find(x);
            int yr = find(y);
            if (xr == yr)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
        {
            int x;
            cin >> x;
            cout << cnt[find(x)] << endl;
        }
    }

    return 0;
}
