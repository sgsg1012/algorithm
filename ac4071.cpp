/*
https://www.acwing.com/problem/content/4074/ 
 */
#include <iostream>
using namespace std;
// const int N =10;
// int a[N][N];
int cx, cy, mx, my;
bool check(int x, int y)
{
    if (x == cx)
        return false;
    if (y == cy)
        return false;
    if (x == mx && y == my)
        return false;
    if (abs(x - mx) == 1 && abs(y - my) == 2)
        return false;
    if (abs(y - my) == 1 && abs(x - mx) == 2)
        return false;
    if (abs(x - cx) == 1 && abs(y - cy) == 2)
        return false;
    if (abs(y - cy) == 1 && abs(x - cx) == 2)
        return false;
    return true;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cx = s1[0] - 'a' + 1;
    mx = s2[0] - 'a' + 1;
    cy = s1[1] - '0';
    my = s2[1] - '0';
    int num = 0;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (check(i, j))
                num++;
        }
    }
    cout << num << endl;
    return 0;
}