#include <iostream>
#include <vector>
using namespace std;
vector<int> highAdd(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int t = 0;
    int i = 0;
    while (i < a.size() || i < b.size())
    {
        if (i < a.size())
            t += a[i];
        if (i < b.size())
            t += b[i];
        ans.push_back(t % 10);
        t /= 10;
        i++;
    }
    if (t)
        ans.push_back(t);
    return ans;
}
int main()
{
    string s1, s2;
    vector<int> a, b;
    cin >> s1 >> s2;
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        a.push_back(s1[i] - '0');
    }
    for (int i = s2.length() - 1; i >= 0; i--)
    {
        b.push_back(s2[i] - '0');
    }
    auto ans = highAdd(a, b);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}