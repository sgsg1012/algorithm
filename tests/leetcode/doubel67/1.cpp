/* https://leetcode-cn.com/problems/find-subsequence-of-length-k-with-the-largest-sum/ */
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> idx;
        for(int i=0;i<nums.size();i++) idx.push_back(i);
        sort(idx.begin(),idx.end(),[&](int a,int b){
            return nums[a]>nums[b];
        });
        vector<int> kidx;
        for(int  i=0;i<k;i++)
        {
            kidx.push_back(idx[i]);
        }
        sort(kidx.begin(),kidx.end());
        for(int i=0;i<k;i++)
        {
            kidx[i]=nums[kidx[i]];
        }
        return kidx;
    }
};