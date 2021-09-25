/* 
模拟堆
    链接：https://www.acwing.com/problem/content/841/
 */
#include <iostream>
using namespace std;
const int N = 100010;
int ph[N], hp[N], h[N];
int s = 0;
int idx = 0;

void hswap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}
void down(int x)
{
    int u = x;
    if (x * 2 <= s && h[x * 2] < h[u])
        u = x * 2;
    if (x * 2 + 1 <= s && h[x * 2 + 1] < h[u])
        u = x * 2 + 1;
    if (u != x)
    {
        hswap(u, x);
        down(u);
    }
}
void up(int x)
{
    if (x / 2 > 0 && h[x / 2] > h[x])
    {
        hswap(x, x / 2);
        up(x / 2);
    }
}
int main()
{
    int n;
    cin >> n;
    string op;
    while (n--)
    {
        cin >> op;
        if (op == "I")
        {
            int x;
            cin >> x;
            s++;
            idx++;
            h[s] = x;
            ph[idx] = s;
            hp[s] = idx;
            up(s);
        }
        else if (op == "PM")
            cout << h[1] << endl;
        else if (op == "DM")
        {
            hswap(1, s);
            s--;
            down(1);
        }
        else if (op == "D")
        {
            int k;
            cin >> k;
            int hk = ph[k];
            hswap(hk, s);
            s--;
            down(hk);
            up(hk);
        }
        else
        {
            int k;
            cin >> k;
            int x;
            cin >> x;
            int hk = ph[k];
            h[hk] = x;
            down(hk);
            up(hk);
        }
    }

    return 0;
}