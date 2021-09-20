/* 1、最长连续不重复子序列
    题目链接：https://www.acwing.com/problem/content/801/
 */
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;
int q[N];
int tag[N];
int main()
{
    memset(tag, 0, sizeof(tag));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    int i = 0, j = 0;
    int num = 0;
    while (i < n && j < n)
    {
        if (tag[q[j]] != 0)
        {
            num = max(num, j - i);
            tag[q[i]]--;
            i++;
        }
        else
        {
            tag[q[j]]++;
            j++;
        }
    }
    num = max(num, j - i);
    cout << num << endl;
    return 0;
}

/* 思路一样 但是更加简洁  */
/* 上面那个当有重复时每一次只向前走一步，这个通过while循环直接走到没有重复的位置然后计算长度，更合理 */
// #include <iostream>
// #include <cstring>
// using namespace std;
// const int N = 100010;
// int q[N];
// int tag[N];
// int main()
// {
//     memset(tag, 0, sizeof(tag));
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> q[i];
//     int i = 0, j = 0;
//     int num = 0;
//     while (i < n && j < n)
//     {
//         while (tag[q[j]] != 0)
//         {
//             tag[q[i]]--;
//             i++;
//         }
//         num = max(num, j - i + 1);
//         tag[q[j]]++;
//         j++;
//     }
//     cout << num << endl;
//     return 0;
// }