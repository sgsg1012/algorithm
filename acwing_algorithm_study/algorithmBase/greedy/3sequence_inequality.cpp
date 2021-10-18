/* 
排队打水 链接：https://www.acwing.com/problem/content/description/915/
    升序
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100100;
int seq[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    sort(seq, seq + n);
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += seq[i] * (n - i - 1);
    }
    cout << sum << endl;
    return 0;
}