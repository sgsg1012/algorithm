/* 
排列数字
    链接：https://www.acwing.com/problem/content/844/
 */
#include <iostream>
using namespace std;
const int N = 10;
bool tag[N];
int seq[N];
int n;
void dfs(int len)
{
    if (len >= n)
    {
        for (int i = 0; i < len; i++)
            cout << seq[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!tag[i])
        {
            seq[len] = i + 1;
            tag[i] = true;
            dfs(len + 1);
            tag[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
    return 0;
}