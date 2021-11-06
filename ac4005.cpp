#include <iostream>
using namespace std;

int k;
bool game(int n)
{
    if (n == 0)
        return false;
    bool a = true, b = true, c = true;
    if (n >= 1)
        a = game(n - 1);
    if (n >= 2)
        b = game(n - 2);
    if (n >= k)
        c = game(n - k);
    if (a && b && c)
        return false;
    return true;
}
int main()
{
    int n;
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
    {
        if (game(i))
            cout << 1 << " ";
        else
            cout << 0 << " ";
        // if ((i + 1) % (k + 1) == 0)
        //     cout << endl;
    }
    cout << endl;
    system("pause");
    return 0;
}