/* https://leetcode-cn.com/problems/find-good-days-to-rob-the-bank/ */
/* 写得头疼，一定有更好的思路，找时间看看 */
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        vector<int> ans;
        int len=s.size();
        vector<int> up;
        vector<int> down;
        for(int i=0;i<len;i++)
        {
            if(i+1<len&&s[i]<s[i+1]) up.push_back(i);
            if(i+1<len&&s[i]>s[i+1]) down.push_back(i);
        }
        // for(int i=0;i<up.size();i++) cout<<up[i]<<" ";
        // cout<<endl;
        int idxu=0;
        int idxd=0;
        int lastUp,nextDown;
        for(int i=0;i<len;i++)
        {
            if(i-time>=0&&i+time<len)
            {
                if(idxu<0) idxu=0;
                while(idxu<up.size()&&up[idxu]<i) idxu++;
                idxu--;
                if(idxu>=0) lastUp=up[idxu];
                else lastUp=-1;
                while(idxd<down.size()&&down[idxd]<i) idxd++;
                if(idxd<down.size()) nextDown=down[idxd];
                else nextDown=len-1;
                // if(i==5) cout<<lastUp<<endl;
                if(lastUp<i-time&&nextDown>=i+time) ans.push_back(i);
            }
        }
        return ans;
    }
};