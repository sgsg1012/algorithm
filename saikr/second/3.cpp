#include <iostream>
#include <cstring>
using namespace std;
const int N = 200200;
int h[N];
int val[N];
int ne[N];
int idx = 0;
int a[N];
void add(int x, int y)
{
    val[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}
void dfs(int x, int k)
{
    int tem = h[x];
    a[x] += k;
    for (tem = h[x]; tem != -1; tem = ne[tem])
    {
        dfs(val[tem], k);
    }
}
int query(int x)
{
    int tem = h[x];
    int ans = a[x];
    for (tem = h[x]; tem != -1; tem = ne[tem])
    {
        ans = max(ans, query(val[tem]));
    }
    return ans;
}
int find(int s, int g)
{
    if (s == g)
    {
        return a[s];
    }
    int tem = h[s];
    int ans = 0;
    for (; tem != -1; tem = ne[tem])
    {
        int j = val[tem];
        ans = max(find(j, g), ans);
    }
    if (ans == 0)
        return 0;
    else
        return ans + a[s];
}
int findMax(int s)
{
    int ans = 0;
    int tem = h[s];
    for (; tem != -1; tem = ne[tem])
    {
        int j = val[tem];
        ans = max(ans, findMax(j) + a[j]);
    }
    return ans;
}
int main()
{
    for (int i = 0; i < N; i++)
        h[i] = -1;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        add(x, y);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, k;
            cin >> x >> k;
            // dfs(x, k);
            a[x] += k;
        }
        else
        {
            int x;
            cin >> x;
            int ahead = find(1, x);

            cout << ahead + findMax(x) << endl;
        }
    }
    system("pause");
    return 0;
}