/* 
双链表：https://www.acwing.com/problem/content/829/
 */
#include <iostream>
using namespace std;
const int N = 100010;
int val[N], l[N], r[N];
int idx = 2;
void init()
{
    r[0] = 1;
    l[1] = 0;
    l[0] = -1;
    r[1] = -1;
}
void leftInsert(int x)
{
    val[idx] = x;
    r[idx] = r[0];
    l[r[0]] = idx;
    r[0] = idx;
    l[idx] = 0;
    idx++;
}
void rightInsert(int x)
{
    val[idx] = x;
    l[idx] = l[1];
    r[l[1]] = idx;
    l[1] = idx;
    r[idx] = 1;
    idx++;
}
void delK(int k)
{
    r[l[k + 1]] = r[k + 1];
    l[r[k + 1]] = l[k + 1];
}
void insertLeftK(int k, int x)
{
    val[idx] = x;
    l[idx] = l[k + 1];
    r[idx] = k + 1;
    r[l[k + 1]] = idx;
    l[k + 1] = idx;
    idx++;
}
void insertRightK(int k, int x)
{
    val[idx] = x;
    l[idx] = k + 1;
    r[idx] = r[k + 1];
    l[r[k + 1]] = idx;
    r[k + 1] = idx;
    idx++;
}
int main()
{
    int m;
    cin >> m;
    string op;
    init();
    while (m--)
    {
        cin >> op;
        if (op == "L")
        {
            int x;
            cin >> x;
            leftInsert(x);
        }
        else if (op == "R")
        {
            int x;
            cin >> x;
            rightInsert(x);
        }
        else if (op == "D")
        {
            int k;
            cin >> k;
            delK(k);
        }
        else if (op == "IL")
        {
            int k;
            int x;
            cin >> k >> x;
            insertLeftK(k, x);
        }
        else
        {
            int k;
            int x;
            cin >> k >> x;
            insertRightK(k, x);
        }
    }
    int i = r[0];
    for (; i != 1; i = r[i])
    {
        cout << val[i] << " ";
    }
    cout << endl;
    // system("pause");
    return 0;
}