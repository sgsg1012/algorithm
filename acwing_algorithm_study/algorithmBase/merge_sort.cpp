/* 
归并排序：
    思路很简单 分治
    先分两半后按顺序合起来
    但是自己写的话代码不是很好写，所以记住下面的写法，真的是优美
 */
#include <iostream>
using namespace std;
const int N = 100010;
int seq[N];
int tem[N];
int n;
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
        if (q[i] < q[j])
            tem[k++] = q[i++];
        else
            tem[k++] = q[j++];
    }
    while (i <= middle)
        tem[k++] = q[i++];
    while (j <= r)
        tem[k++] = q[j++];
    for (i = l, k = 0; i <= r; i++, k++)
    {
        q[i] = tem[k];
    }
    return;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }
    merge_sort(seq, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << seq[i] << " ";
    }
    cout << endl;
}