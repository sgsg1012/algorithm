/* 
改变左右范围时注意middle的取值
int mid = i + j + 1 >> 1;
到底加不加1
可能会无限循环
 */
/* 
二分的本质不是单调性
而是找边界点，使得在边界点左边的数据满足一种性质，右边的数据满足另一种性质 两种性质互斥即可
使用二分时要合理构造性质使得要找的那个点是边界点即可，一般很容易找
 */
#include <iostream>
using namespace std;
const int N = 100010;
int seq[N];
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }
    while (q--)
    {
        int k;
        cin >> k;
        int l, r;
        int i = 0, j = n - 1;
        while (i < j)
        {
            int mid = i + j + 1 >> 1;
            if (seq[mid] < k)
                i = mid;
            else
                j = mid - 1;
        }
        if (seq[i + 1] != k && seq[i] != k)
        {
            cout << "-1 -1" << endl;
            continue;
        }
        if (seq[i] != k)
            l = i + 1;
        else
            l = i;
        i = 0, j = n - 1;
        while (i < j)
        {
            int mid = i + j >> 1;
            if (seq[mid] > k)
                j = mid;
            else
                i = mid + 1;
        }
        if (seq[i] == k)
            r = i;
        else
            r = i - 1;
        cout << l << " " << r << endl;
    }
    return 0;
}