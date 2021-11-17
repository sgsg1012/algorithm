/* 
https://www.acwing.com/problem/content/847/
 */
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
string goal = "12345678x";
string myswap(string s, int a, int b)
{
    swap(s[a], s[b]);
    return s;
}
int bfs(string s)
{
    queue<string> q;
    q.push(s);
    unordered_map<string, int> m;
    m[s] = 0;
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    while (q.size())
    {
        auto t = q.front();
        if (t == goal)
            return m[t];
        q.pop();
        int pos = t.find('x');
        int x = pos / 3;
        int y = pos % 3;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx <= 2 && ny >= 0 && ny <= 2)
            {
                int d = m[t];
                int npos = nx * 3 + ny;
                string nt = myswap(t, pos, npos);
                if (m.count(nt) > 0)
                    continue;
                q.push(nt);
                m[nt] = d + 1;
            }
        }
    }
    return -1;
}
int main()
{
    string a, b;
    int n = 9;
    while (n--)
    {
        cin >> a;
        b += a;
    }
    cout << bfs(b) << endl;
    system("pause");
    return 0;
}