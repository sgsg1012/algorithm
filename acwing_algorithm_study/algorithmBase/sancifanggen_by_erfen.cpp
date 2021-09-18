/* 
浮点数二分 简单
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
int main()
{
    double n = 0;
    bool fu = 0;
    cin >> n;
    if (n < 0)
        fu = 1, n *= -1;
    if (n >= 1.0)
    {
        double l = 0, r = n;
        while (r - l > 1e-8)
        {
            double middle = (l + r) / 2;
            if (middle * middle * middle <= n)
                l = middle;
            else
                r = middle;
        }
        if (!fu)
            printf("%.6lf\n", r);
        else
            printf("%.6lf\n", -r);
    }
    else
    {
        double l = 0, r = 1.0;
        while (r - l > 1e-8)
        {
            double middle = (l + r) / 2;
            if (middle * middle * middle <= n)
                l = middle;
            else
                r = middle;
        }
        if (!fu)
            printf("%.6lf\n", r);
        else
            printf("%.6lf\n", -r);
    }
}