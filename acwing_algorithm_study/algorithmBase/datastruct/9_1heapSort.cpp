/* 
堆排序
    链接：https://www.acwing.com/problem/content/840/
 */
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;
int h[N];
int s = 0;
void down(int t)
{
    int u = t;
    if (t * 2 <= s && h[t * 2] < h[u])
        u = t * 2;
    if (t * 2 + 1 <= s && h[t * 2 + 1] < h[u])
        u = t * 2 + 1;
    if (u != t)
    {
        swap(h[t], h[u]);
        down(u);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i], ++s;
    for (int i = n / 2; i; i--)
        down(i);
    while (m--)
    {
        cout << h[1] << " ";
        h[1] = h[s];
        s--;
        down(1);
    }
    return 0;
}