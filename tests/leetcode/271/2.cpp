/* https://leetcode-cn.com/problems/sum-of-subarray-ranges/ */
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int len=nums.size();
        long long ans=0;
        int mxd[1100];
        int hx=0,tx=0;
        int mnd[1100];
        int hn=0,tn=0;
        for(int i=2;i<=len;i++)
        {
            hx=tx=0;
            hn=tn=0;
            for(int j=0;j<len;j++)
            {
                if(hx<tx&&mxd[hx]<j-i+1) hx++;
                while(!(tx-hx==0||nums[mxd[tx-1]]>=nums[j])) tx--;
                mxd[tx++]=j;
                if(hn<tn&&mnd[hn]<j-i+1) hn++;
                while(!(tn-hn==0||nums[mnd[tn-1]]<=nums[j])) tn--;
                mnd[tn++]=j;
                if(j>=i-1) 
                {
                    ans+=nums[mxd[hx]]-nums[mnd[hn]];
                }
            }
        }
        return ans;
    }
};