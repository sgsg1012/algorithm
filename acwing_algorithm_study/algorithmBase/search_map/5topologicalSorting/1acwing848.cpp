/* https://www.acwing.com/problem/content/850/ 
    入度
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N = 100010;
int h[N], e[N], ne[N];
int idx;
bool st[N];
int n, m;
int d[N]; //入度
vector<int> ans;
void add(int x, int y)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}
void toffer()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        auto t = q.front();
        ans.push_back(t);
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] > 0)
            {
                d[j]--;
                if (d[j] == 0)
                    q.push(j);
            }
        }
    }
}
int main()
{
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    toffer();
    if (ans.size() < n)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}