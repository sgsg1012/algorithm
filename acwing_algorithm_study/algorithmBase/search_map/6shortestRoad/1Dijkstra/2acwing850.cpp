/* https://www.acwing.com/problem/content/852/ */
/* 
搞一个set或者小根堆来维护未确定最短距离的集合，降低时间复杂度
更新距离是一个问题，实际上，不用考虑如何修改，直接将要更新的值加到表中，取节点时判断一下，重复的自会忽略掉
 */
#include <iostream>
#include <cstring>
#include <set>
using namespace std;
struct node
{
    int idx;
    int dist;
    bool operator<(node a) const
    {
        return dist < a.dist;
    }
};
const int N = 160000;
int h[N], e[N], ne[N], w[N];
int idx;
int n, m;
bool st[N];
int dist[N];
void add(int a, int b, int l)
{
    e[idx] = b;
    w[idx] = l;
    ne[idx] = h[a];
    h[a] = idx++;
}
int dijkstar()
{
    for (int i = 0; i < N; i++)
    {
        dist[i] = 1e9;
    }
    multiset<node> s;
    node r;
    r.dist = 0;
    r.idx = 1;
    st[1] = true;
    dist[1] = 0;
    for (int i = h[1]; i != -1; i = ne[i])
    {
        int j = e[i];
        dist[j] = min(dist[j], dist[1] + w[i]);
        node t;
        t.dist = dist[j];
        t.idx = j;
        s.insert(t);
    }
    while (true)
    {
        auto t = *s.begin();
        s.erase(s.begin());
        if (st[t.idx])
            continue;
        st[t.idx] = true;
        if (t.idx == n)
        {
            if (t.dist >= 100000000)
                return -1;
            return t.dist;
        }
        int idx = t.idx;
        for (int i = h[idx]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[idx] + w[i] < dist[j])
            {
                dist[j] = dist[idx] + w[i];
                node t;
                t.dist = dist[j];
                t.idx = j;
                s.insert(t);
            }
        }
    }
}
int main()
{
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    int a, b, l;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> l;
        add(a, b, l);
    }
    dijkstar();
    system("pause");
    return 0;
}