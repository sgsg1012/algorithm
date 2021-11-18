#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 100010;
int h[N], e[N * 2], ne[N * 2];
int idx = 0;
bool st[N];
int n, m;
void add(int x, int y)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
    idx++;
}
int bfs()
{
    queue<int> q;
    int ans = 0;
    q.push(1);
    st[1] = true;
    while (q.size())
    {
        int len = q.size();
        while (len--)
        {
            auto t = q.front();
            if (t == n)
                return ans;
            q.pop();
            for (int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
        ans++;
    }
    return -1;
}
int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}