#include <iostream>
using namespace std;
const int N = 550;
int a[N][N];
int main()
{
    int n, m, L;
    cin >> n >> m >> L;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int k = 0; k < L; k++)
    {
        int num = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == k)
                    num++;
            }
        }
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

/* #include <iostream>
#include <cstdio>
using namespace std;
const int N = 510;
int ans[300];
int n, m, l;
int main()
{
    cin >> n >> m >> l;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int x;
            scanf("%d", &x);
            ans[x]++;
        }
    for (int i = 0; i < l; i++)
        printf("%d ", ans[i]);
    cout << endl;
    return 0;
} */