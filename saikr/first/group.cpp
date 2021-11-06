#include <iostream>
using namespace std;
unsigned long long J(int n)
{
    if (n <= 1)
        return 1;
    return n * J(n - 1);
}
unsigned long long f(int n, int m)
{
    return (J(n) / J(n - m)) / J(m);
}
const int mod = 998244353;
int n;
unsigned long long dp(int n, int m)
{
    if (m == 0)
        return 1;
    if (n < m * 2)
        return 0;
    unsigned long long x = 0;
    for (int i = 0; i <= (n - 2); i++)
    {
        int j = n - 2 - i;
        unsigned num = 0;
        for (int k = 0; k <= (m - 1) / 2 && k <= i / 2; k++)
        {
            num += dp(i, k) * dp(j, m - 1 - k);
        }
        x += num;
    }
    return x;
}
unsigned long long group(int k)
{
    int m = min(n - k, k);
    unsigned long long num = 0;
    for (int i = 0; i <= m; i++)
    {

        num = (num + dp(n, i) * f(n - 2 * i, k - i)) % mod;
    }
    return num;
}
int main()
{

    int k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cout << group(i) << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}