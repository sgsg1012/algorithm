#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void getNextval(string &t, int *&nextval)
{
    nextval[0] = -1;
    int j = 0;
    int k = -1;
    while (j < t.length() - 1)
    {
        if (k == -1 || t[j] == t[k])
        {
            j++;
            k++;
            if (t[j] != t[k])
            {
                nextval[j] = k;
            }
            else
                nextval[j] = nextval[k];
        }
        else
            k = nextval[k];
    }
}
int kmp(string &s, string &t)
{
    const int len = t.length();
    int *nextval = new int(len * sizeof(int));
    getNextval(t, nextval);
    int i = 0, j = 0;
    while (i < s.length() && j < t.length())
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nextval[j];
        }
    }
    if (j >= t.length())
        return i - t.length();
    else
        return -1;
}
int main()
{
    string s;
    string t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    cout << s.length() - kmp(s, t) - t.length() << endl;
    int x;
    cin >> x;
    return 0;
}