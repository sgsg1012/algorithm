#include <iostream>
#include <set>
using namespace std;
const int N = 100010;
int sum[N][N / 10];
struct node
{
    int a, b, w;
    bool operator<(node a) const
    {
        return w < a.w;
    }
};
bool st[N];
int main()
{
    int n, m;
    cin >> n >> m;
    multiset<node> s;
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        node t;
        t.a = a;
        t.b = b;
        t.w = w;
        s.insert(t);
    }
    int len = 1;
    int ans = 0;
    st[1] = true;
    while (len < n)
    {
        auto idx = s.begin();
        auto t = *idx;
        while (!(st[t.a] || st[t.b]) && idx != s.end())
        {
            idx++;
            t = *idx;
        }
        if (idx == s.end())
        {
            cout << "impossible" << endl;
            return 0;
        }
        s.erase(idx);
        if (st[t.a] && st[t.b])
        {
            continue;
        }
        st[t.a] = st[t.b] = true;
        len++;
        ans += t.w;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}