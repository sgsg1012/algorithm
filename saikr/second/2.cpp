#include <iostream>
#include <vector>
using namespace std;
const int N = 200200;
int a[N];
vector<int> arr[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            int k;
            cin >> x >> k;
            for (int i = 0; i < arr[x].size(); i++)
            {
                a[arr[x][i]] += k;
            }
        }
        else
        {
            int x;
            cin >> x;
            int ans = 0;
            for (int i = 0; i < arr[x].size(); i++)
            {
                ans = max(ans, a[arr[x][i]]);
            }
            cout << ans << endl;
        }
    }
    system("pause");
    return 0;
}