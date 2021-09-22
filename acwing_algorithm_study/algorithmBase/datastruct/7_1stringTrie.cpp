/* 
Trie字符串统计
    链接：https://www.acwing.com/problem/content/837/

本质应该是一种树形结构
也可以理解为多子节点的链表，它的数组模拟和单链表就差不多了
区别在于单链表的ne[]数组是一维数组，因为每个节点的子节点只有一个
串不一样 比如字符串统计那一题，一个节点最多可以有26个子节点，所以ne数组是N*26

这样理解比较好一点
 */
#include <iostream>
using namespace std;
const int N = 100010;
int ne[N][26]; //头结点0, 0也表示null
int cnt[N];
int idx;
void insert(string s)
{
    int p = 0; //头结点
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        int c = s[i] - 'a';
        if (ne[p][c] == 0)
            ne[p][c] = ++idx;
        p = ne[p][c];
    }
    cnt[p]++;
}
int count(string s)
{
    int len = s.length();
    int p = 0;
    for (int i = 0; i < len; i++)
    {
        int c = s[i] - 'a';
        if (ne[p][c] == 0)
            return 0;
    }
    return cnt[p];
}
int main()
{
    int n;
    cin >> n;
    string s;
    char c;
    while (n--)
    {
        cin >> c;
        if (c == 'I')
        {
            cin >> s;
            insert(s);
        }
        else
        {
            cin >> s;
            cout << count(s) << endl;
        }
    }

    return 0;
}