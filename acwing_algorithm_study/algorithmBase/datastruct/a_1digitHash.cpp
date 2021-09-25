/* 
模拟散列表：
    链接：https://www.acwing.com/problem/content/842/
 */
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100003;
int h[N];
int val[N], ne[N];
int idx;
int find(int x)
{
    return (x % N + N) % N;
}
int main()
{
    memset(h, -1, sizeof h);
    int n;
    cin >> n;
    while (n--)
    {
        string op;
        cin >> op;
        if (op == "I")
        {
            int x;
            cin >> x;
            int pos = find(x);
            val[idx] = x;
            ne[idx] = h[pos];
            h[pos] = idx++;
        }
        else
        {
            int x;
            cin >> x;
            int pos = find(x);
            int i = 0;
            for (i = h[pos]; i != -1; i = ne[i])
            {
                if (val[i] == x)
                {
                    cout << "Yes" << endl;
                    break;
                }
            }
            if (i == -1)
                cout << "No" << endl;
        }
    }
    return 0;
}