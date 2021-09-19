/* 
高精度乘以低精度
    不要想得太复杂 比高加还要简单
    就是进位从1变成了很大而已
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> highMul(vector<int> &a, int b)
{
    int t = 0;
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        t = a[i] * b + t;
        ans.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        ans.push_back(t % 10);
        t /= 10;
    }
    return ans;
}
int main()
{
    string s1;
    int b;
    cin >> s1 >> b;
    if (b == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> a;
    for (int i = s1.length() - 1; i >= 0; i--)
        a.push_back(s1[i] - '0');
    auto ans = highMul(a, b);
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << endl;
    return 0;
}