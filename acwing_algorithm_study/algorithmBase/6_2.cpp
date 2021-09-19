/* 
    2、 数组元素的目标和
    题目链接：https://www.acwing.com/problem/content/802/
    太简单了
 */
/* 双指针做法 O(N) */
// #include <iostream>
// using namespace std;
// const int N = 100010;
// int a[N];
// int b[N];
// int main()
// {
//     int n, m, x;
//     cin >> n >> m >> x;
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     for (int i = 0; i < m; i++)
//         cin >> b[i];
//     int i = 0, j = m - 1;
//     while (a[i] + b[j] != x)
//     {
//         if (a[i] + b[j] < x)
//         {
//             i++;
//         }
//         else
//         {
//             j--;
//         }
//     }
//     cout << i << " " << j << endl;
//     return 0;
// }
/* 二分 O(nlogn) */
#include <iostream>
using namespace std;
const int N = 100010;
int a[N];
int b[N];
int findByErfen(int a[], int l, int r, int x)
{
    while (l < r)
    {
        int middle = l + r >> 1;
        if (a[middle] >= x)
        {
            r = middle;
        }
        else
        {
            l = middle + 1;
        }
    }
    if (a[l] == x)
        return l;
    else
        return -1;
}
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        int loc = findByErfen(a, 0, n - 1, x - b[i]);
        if (loc != -1)
        {
            cout << loc << " " << i << endl;
            system("pause");
            return 0;
        }
    }
    system("pause");
    return 0;
}