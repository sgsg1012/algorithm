#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    int x, y;
};
const int N = 55;
char a[N][N];
vector<node> first;
vector<node> second;
void bfs(node start, vector<node> &first)
{
    queue<node> q;
    bool check[N][N];
    check[start.x][start.y] = 1;
    first.push_back(start);
    q.push(start);
    int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
    while (q.size())
    {
        node tem = q.front();
        q.pop();
        int x = tem.x;
        int y = tem.y;
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (a[newX][newY] == '0' && check[newX][newY] == false)
            {
                node a;
                a.x = newX;
                a.y = newY;
                first.push_back(a);
                q.push(a);
                check[newX][newY] = true;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    node s, g;
    cin >> s.x >> s.y;
    cin >> g.x >> g.y;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = '1';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    bfs(s, first);
    bfs(g, second);
    cout << first.size() << endl;
    cout << second.size() << endl;
    int ans = 1000000000;
    for (int i = 0; i < first.size(); i++)
    {
        for (int j = 0; j < second.size(); j++)
        {
            ans = min(ans, (first[i].x - second[j].x) * (first[i].x - second[j].x) + (first[i].y - second[j].y) * (first[i].y - second[j].y));
            if (ans == 0)
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}