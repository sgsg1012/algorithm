/* 
货仓选址 链接：https://www.acwing.com/problem/content/106/
    中点
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
    int mid = seq[n / 2];
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += abs(mid - seq[i]);
    }
    cout << sum << endl;
    return 0;
}