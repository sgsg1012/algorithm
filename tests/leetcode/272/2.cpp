/* https://leetcode-cn.com/problems/adding-spaces-to-a-string/ */
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int len=s.size();
        int idx=0;
        int spaceLen=spaces.size();
        for(int i=0;i<len;i++)
        {
            if(idx<spaceLen&&i==spaces[idx])
            {
                ans+=' ';
                idx++;
            }
            ans+=s[i];
        }
        return ans;
    }
};