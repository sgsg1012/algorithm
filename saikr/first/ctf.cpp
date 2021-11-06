#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    unsigned long long x = 0;
    int n = 0;
    for (n = 0; n < t; n++)
    {
        if (pow(2, n + 1) - 2 > t)
            break;
    }
    n--;
    int m = t - pow(2, n + 1) + 2;
    for (int i = 0; i <= n; i++)
    {
        x += pow(2, i) * i;
    }
    x += m * (n + 1);
    cout << x << endl;
    system("pause");

    return 0;
}