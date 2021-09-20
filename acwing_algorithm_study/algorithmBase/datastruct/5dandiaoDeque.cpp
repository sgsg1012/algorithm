/* 
滑动窗口 链接：https://www.acwing.com/problem/content/156/
单调队列入门题
维护一个单调队列就可以 我之前一直纠结于怎么处理出队的时机 
没想到队列里存的是数组下标 直接判断下标是否超出范围即可
真 绝了！
 */

#include <iostream>
#include <vector>
using namespace std;
const int N = 1000010;
int h = 0, t = 0;
int a[N];
int q[N];
int main()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> minans;
    vector<int> maxans;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (q[h] < i - k + 1)
            h++;
        while (h < t && a[q[t - 1]] >= a[i])
            t--;
        q[t++] = i;
        if (i >= k - 1)
            minans.push_back(a[q[h]]);
    }
    h = t = 0;
    for (int i = 0; i < n; i++)
    {
        if (q[h] < i - k + 1)
            h++;
        while (h < t && a[q[t - 1]] <= a[i])
            t--;
        q[t++] = i;
        if (i >= k - 1)
            maxans.push_back(a[q[h]]);
    }
    for (int i = 0; i < minans.size(); i++)
    {
        cout << minans[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < maxans.size(); i++)
    {
        cout << maxans[i] << " ";
    }
    return 0;
}