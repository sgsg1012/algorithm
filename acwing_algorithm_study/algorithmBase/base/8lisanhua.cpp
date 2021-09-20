/* 
整数有序离散化:
区间和：https://www.acwing.com/problem/content/804/
思路：
把要插入的位置放在数组里，用数组下表代替插入位置实现数据范围的缩小
之前我一直在已有映射数组的前提下处理新插入的位置，比如说有没有重复的，插在哪个位置等等
但是这其实很容易处理，只需要把所有要用到的坐标先全部存入一个vector中(要求开数组时)，之后对vector去重，然后排序，这样映射关系就建立了，并且不会发生变化(因为所有数据都处理完了)
草啊，原来这么简单
映射关系确定后就要处理查找映射了，就是给一个坐标值，找到在数组中的下标，这个很简单，二分就可以了
然后就前缀和数组就可以了

 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 300030;
int a[N], s[N];
vector<int> alls;
vector<PII> add, query;
int findByErfen(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l + 1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    s[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back(pair<int, int>(x, c));
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back(pair<int, int>(l, r));
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for (int i = 0; i < n; i++)
    {
        int loc = findByErfen(add[i].first);
        a[loc] += add[i].second;
    }
    for (int i = 1; i <= alls.size(); i++)
    {
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 0; i < m; i++)
    {
        int l = findByErfen(query[i].first);
        int r = findByErfen(query[i].second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}