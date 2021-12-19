/* https://leetcode-cn.com/problems/maximum-fruits-harvested-after-at-most-k-steps/ 
前缀和 没看出来 可惜
*/
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int start, int k) {
        vector<int> pre(200010);
        int n=200010;
        int idx=0;
        for(int i=0;i<n;i++)
        {
            if(idx<fruits.size()&&i>=fruits[idx][0]) 
            {
                if(i>0) pre[i]=pre[i-1]+fruits[idx][1];
                else pre[i]=fruits[idx][1];
                idx++;
            }
            else 
            {
                if(i>0) pre[i]=pre[i-1];
                else pre[i]=0;
            }
        }
        int ans=0;
        for(int x=0;x*2<=k;x++)
        {
            int y=k-x*2;
            int r=min(start+y,n-1);
            int l=max(0,start-x);
            if(l==0) ans=max(ans,pre[r]);
            else ans=max(ans,pre[r]-pre[l-1]);
        }
        for(int x=0;x<=k;x++)
        {
            int y=(k-x)/2;
            int r=min(start+y,n-1);
            int l=max(0,start-x);
            if(l==0) ans=max(ans,pre[r]);
            else ans=max(ans,pre[r]-pre[l-1]);
        }
        return ans;
    }
};
