/* 
    kmp 链接：https://www.acwing.com/problem/content/833/
 */
/* 
    下标从0开始的kmp算法  数据结构课本上的 这个更容易理解
    并且是改进版的
    next[]-------->nextval[]
    不懂的话去看书
    https://baike.baidu.com/item/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E6%95%99%E7%A8%8B%EF%BC%88%E7%AC%AC5%E7%89%88%EF%BC%89/22216268?fr=aladdin
 */
#include <iostream>
using namespace std;
const int N = 100010;
int nextval[N];
void getNextval(string &t)
{
    nextval[0] = -1;
    int j = 0;
    int k = -1;
    while (j < t.length())
    {
        if (k == -1 || t[j] == t[k])
        {
            j++;
            k++;
            if (t[j] != t[k])
            {
                nextval[j] = k;
            }
            else
                nextval[j] = nextval[k];
        }
        else
            k = nextval[k];
    }
}
void kmp(string &s, string &t)
{
    int i = 0, j = 0;
    int len = t.length();
    while (i < s.length())
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nextval[j];
        }
        if (j >= len)
            cout << i - len << " ";
    }
    cout << endl;
}
int main()
{
    string s, t;
    int n, m;
    cin >> n >> t >> m >> s;
    getNextval(t);
    kmp(s, t);
    return 0;
}