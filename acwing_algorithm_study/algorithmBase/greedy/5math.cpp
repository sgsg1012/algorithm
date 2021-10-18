/* 
耍杂技的牛 链接：https://www.acwing.com/problem/content/127/
    题解：https://www.acwing.com/solution/content/34255/
    tql
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100100;
struct ox
{
    int weight;
    int strong;
    bool operator<(const ox &a)
    {
        return weight + strong < a.weight + a.strong;
    }
} oxes[N];
int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> oxes[i].weight >> oxes[i].strong;
    }
    sort(oxes, oxes + n);
    long long ans = -1e10;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, sum - oxes[i].strong);
        sum += oxes[i].weight;
    }
    cout << ans << endl;
    return 0;
}