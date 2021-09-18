/*
归并排序的应用
注意在左边的数字大于右边时num要增加多少
还有就是千万注意num的大小超过int，用long long 
 */
#include <iostream>
using namespace std;
const int N = 100010;
int seq[N];
int tem[N];
long long num = 0;
void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int middle = l + r >> 1;
    merge_sort(q, l, middle);
    merge_sort(q, middle + 1, r);
    int i = l, j = middle + 1, k = 0;
    while (i <= middle && j <= r)
    {
        if (q[i] <= q[j])
            tem[k++] = q[i++];
        else
        {
            num += middle - i + 1;
            tem[k++] = q[j++];
        }
    }
    while (i <= middle)
    {
        tem[k++] = q[i++];
    }
    while (j <= r)
    {
        tem[k++] = q[j++];
    }
    for (i = l, k = 0; i <= r; i++, k++)
    {
        q[i] = tem[k];
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    merge_sort(seq, 0, n - 1);
    cout << num;
}