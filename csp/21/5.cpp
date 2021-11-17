#include <iostream>
using namespace std;
struct node
{
    unsigned long long x;
    unsigned long long y;
    unsigned long long z;
};
const int N = 1100;
const int mod = 1e9 + 7;
node arr[N];
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int type;
        cin >> type;
        int l, r, a, b, c, k;
        if (type == 1)
        {
            cin >> l >> r >> a >> b >> c;
            for (int i = l; i <= r; i++)
            {
                arr[i].x = (arr[i].x + a) % mod;
                arr[i].y = (arr[i].y + b) % mod;
                arr[i].z = (arr[i].z + c) % mod;
            }
        }
        else if (type == 2)
        {
            cin >> l >> r;
            cin >> k;
            for (int i = l; i <= r; i++)
            {
                arr[i].x = (arr[i].x * k) % mod;
                arr[i].y = (arr[i].y * k) % mod;
                arr[i].z = (arr[i].z * k) % mod;
            }
        }
        else if (type == 3)
        {
            cin >> l >> r;
            for (int i = l; i <= r; i++)
            {
                swap(arr[i].x, arr[i].y);
                swap(arr[i].y, arr[i].z);
            }
        }
        else
        {
            cin >> l >> r;
            unsigned long long x = 0, y = 0, z = 0;
            for (int i = l; i <= r; i++)
            {
                x = (x + arr[i].x) % mod;
                y = (y + arr[i].y) % mod;
                z = (z + arr[i].z) % mod;
            }
            cout << (((x * x) % mod) + ((y * y) % mod) + ((z * z) % mod)) % mod << endl;
        }
    }
    return 0;
}