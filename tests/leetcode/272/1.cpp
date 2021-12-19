/* https://leetcode-cn.com/problems/find-first-palindromic-string-in-the-array/ */
class Solution {
public:
    bool check(string s)
    {
        int len=s.size();
        for(int i=0;i<=len/2;i++)
        {
            if(s[i]!=s[len-1-i]) return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int len=words.size();
        for(int i=0;i<len;i++)
        {
            if(check(words[i]))
            {
                return words[i];
            }
        }
        return "";
    }
};