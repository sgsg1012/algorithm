/* 
高减
    去前导0
    逻辑都很清晰，代码啰嗦一点也没问题，并且还易懂
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> highSub(vector<int> &a, vector<int> &b)
{
    int t = 0;
    vector<int> ans;
    for (int i = 0; i < a.size() || i < b.size(); i++)
    {
        int jianed = 0;
        int jian = a[i] - t;
        if (i < b.size())
            jianed = b[i];
        if (jian < jianed)
        {
            ans.push_back(jian + 10 - jianed);
            t = 1;
        }
        else
        {
            ans.push_back(jian - jianed);
            t = 0;
        }
    }
    return ans;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2)
    {
        cout << 0 << endl;
        return 0;
    }

    bool fu = 0;
    if (s1.length() < s2.length() || (s1.length() == s2.length() && s1 < s2))
    {
        fu = 1;
        string a = s1;
        s1 = s2;
        s2 = a;
    }
    vector<int> a, b;
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        a.push_back(s1[i] - '0');
    }
    for (int i = s2.length() - 1; i >= 0; i--)
    {
        b.push_back(s2[i] - '0');
    }
    auto ans = highSub(a, b);
    if (fu)
        cout << '-';
    bool ling = 1;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ling)
        {
            if (ans[i] != 0)
            {
                ling = 0;
                cout << ans[i];
            }
        }
        else
        {
            cout << ans[i];
        }
    }
    cout << endl;
    return 0;
}