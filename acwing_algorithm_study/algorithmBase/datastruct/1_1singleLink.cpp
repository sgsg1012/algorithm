/* 
单链表 ------->邻接表：用于存储树和图
https://www.acwing.com/problem/content/828/
数组实现单链表：

定义两个数组
1、val[] //存储值  
2、ne[]  // 存储next指针 存的是元素下标

通过下标把两个数组联系起来 
 */
#include <iostream>
using namespace std;
const int N = 100010;
int val[N];
int ne[N];
int idx = 0;
int head = -1;
void headInsert(int x)
{
    val[idx] = x;
    ne[idx] = head;
    head = idx++;
}
void delK(int k)
{
    if (k == 0)
    {
        head = ne[head];
    }
    else
        ne[k - 1] = ne[ne[k - 1]];
}
void insertK(int k, int x)
{
    val[idx] = x;
    ne[idx] = ne[k - 1];
    ne[k - 1] = idx++;
}
int main()
{
    int m;
    cin >> m;
    char op = ' ';
    while (m--)
    {
        cin >> op;
        if (op == 'H')
        {
            int x;
            cin >> x;
            headInsert(x);
        }
        else if (op == 'D')
        {
            int k;
            cin >> k;
            delK(k);
        }
        else
        {
            int k;
            int x;
            cin >> k >> x;
            insertK(k, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
    {
        cout << val[i] << " ";
    }
    cout << endl;
    return 0;
}