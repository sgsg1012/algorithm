#include <iostream>
using namespace std;
const int N = 10;
int a[N];
bool st[N];
int n;
void dfs(int i)
{
    if (i > n)
    {
        for (int k = 1; k <= n; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
        return;
    }
    for (int j = n; j >= 1; j--)
    {
        if (!st[j])
        {
            st[j] = true;
            a[i] = j;
            dfs(i + 1);
            st[j] = false;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    system("pause");
    return 0;
}