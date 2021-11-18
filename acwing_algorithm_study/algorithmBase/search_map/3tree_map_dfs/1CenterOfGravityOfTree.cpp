/* 
https://www.acwing.com/problem/content/848/
树的重心 比较巧妙这一题
 */
#include <iostream>
using namespace std;
const int N = 100100;
int h[N];
int e[N * 2], ne[N * 2];
int idx = 0;
bool st[N * 2];
int n;
int ans = N;
void add(int x, int y)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}
int dfs(int x)
{
    st[x] = true;
    int sum = 1, res = 0;
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            int t = dfs(j);
            sum += t;
            res = max(res, t);
        }
    }
    res = max(res, n - sum);
    ans = min(res, ans);
    st[x] = false;
    return sum;
}
int main()
{

    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}