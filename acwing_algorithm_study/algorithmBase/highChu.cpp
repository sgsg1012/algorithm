/* merchant
remainder */
/* 
注意商为0时要特殊处理
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> highChu(vector<int> &a, int b, int &rem)
{
    vector<int> mer;
    for (int i = 0; i < a.size(); i++)
    {
        rem = rem * 10 + a[i];
        mer.push_back(rem / b);
        rem = rem % b;
    }
    return mer;
}
int main()
{
    string s;
    int b;
    cin >> s >> b;
    vector<int> a;
    for (int i = 0; i < s.length(); i++)
        a.push_back(s[i] - '0');
    int rem = 0;
    auto mer = highChu(a, b, rem);
    bool ling = 1;
    for (int i = 0; i < mer.size(); i++)
    {
        if (ling)
        {
            if (mer[i] != 0)
            {
                ling = 0;
                cout << mer[i];
            }
        }
        else
            cout << mer[i];
    }
    if (ling)
        cout << 0;
    cout << endl;
    cout << rem << endl;
    return 0;
}