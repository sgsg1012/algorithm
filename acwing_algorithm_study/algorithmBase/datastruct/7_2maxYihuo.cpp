/* 
最大异或对
    链接:https://www.acwing.com/problem/content/description/145/
    知道用trie来做的话还是很好想的 就怕不知道 
    知道思路之后 注意二进制位运算需要一点技巧
    
    草啊 我tm还想着把数字变成01字符串，真是个sb

    最后附上y总代码 太漂亮了  

 */
#include <iostream>
using namespace std;
const int N = 32 * 100000 + 10;
int ne[N][2];
int idx;
void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int c = (x >> i) & 1;
        if (!ne[p][c])
            ne[p][c] = ++idx;
        p = ne[p][c];
    }
}
int findMax(int x)
{
    int p = 0;
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        int c = x >> i & 1;
        if (ne[p][!c])
        {
            p = ne[p][!c];
            ans = ans * 2 + !c;
        }
        else
        {
            p = ne[p][c];
            ans = ans * 2 + c;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(x);
        int res = findMax(x);
        ans = max(ans, x ^ res);
    }
    cout << ans << endl;
    return 0;
}

/* ------------------------------------------------------- */

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 3100010;

int n;
int a[N], son[M][2], idx;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int &s = son[p][x >> i & 1];
        if (!s)
            s = ++idx;
        p = s;
    }
}

int search(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int s = x >> i & 1;
        if (son[p][!s])
        {
            res += 1 << i;
            p = son[p][!s];
        }
        else
            p = son[p][s];
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, search(a[i]));

    printf("%d\n", res);

    return 0;
}