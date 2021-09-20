/* 
快排思路：
    随意确定一个分割点，一般选在中间,值记为x
    调整区间，使得区间左边的数全部小于等于x，右边的数全部大于等于x
    递归处理左右两段
特殊处理：
    int i=l-1,j=r+1,x=q[l+r>>1];
    while(i<j){
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    x的取法影响到用i划分区间还是用j划分区间
    原则；
        x取中间靠左，用j划分
        x取中间靠右，用i划分
    原理：用[1,2]来试一下就知道了
 */

#include <iostream>
using namespace std;
const int N = 100010;
int n;
int seq[N];
void quick_sort(int seq[], int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1, j = r + 1, x = seq[l + r >> 1];
    while (i < j)
    {
        do
            i++;
        while (seq[i] < x);
        do
            j--;
        while (seq[j] > x);
        if (i < j)
            swap(seq[i], seq[j]);
    }
    quick_sort(seq, l, j);
    quick_sort(seq, j + 1, r);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    quick_sort(seq, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << seq[i] << " ";
    cout << endl;
    return 0;
}