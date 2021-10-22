/* 
最长上升子序列  链接：https://www.acwing.com/problem/content/897/

状态表示：f[i]--集合：以第i个数结尾的上升子序列  属性：长度最大值
状态转移：easy
 */
/* 
#include <iostream>
using namespace std;
const int N = 1100;
int seq[N];
int f[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> seq[i];
    int Max = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (seq[j] < seq[i])
                f[i] = max(f[i], f[j] + 1);
        }
        Max = max(Max, f[i]);
    }
    cout << Max << endl;
    return 0;
}
 */
/* 优化 */
/* 其实和dp没什么关系了 */
/* 用st数组保存长度为i的上升子序列中最小尾数，那么st数组是递增的 
   这样在插入seq[i]时，只需要找到st数组中小于i的最大的数，加一即为以seq[i]结尾的最长子序列
   注意最后更新st数组
*/
#include <iostream>
using namespace std;
const int N = 1100;
int seq[N];
int st[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> seq[i];
    int len = 0;
    st[0] = -2e9;
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = len;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (st[mid] < seq[i])
                l = mid;
            else
                r = mid - 1;
        }
        len = max(len, r + 1);
        st[r + 1] = seq[i];
    }
    cout << len << endl;
    return 0;
}