/* https://leetcode-cn.com/problems/number-of-smooth-descent-periods-of-a-stock/ */
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int len=prices.size();
        vector<long long> arr;
        int num=0;
        for(int i=0;i<len;i++)
        {
            int last=i-1;
            if(last==-1||prices[last]-prices[i]==1)
            {
                num++;
            }
            else
            {
                arr.push_back(num);
                num=1;
            }
        }
        arr.push_back(num);
        long long ans=0;
        for(int i=0;i<arr.size();i++)
        {
            // cout<<arr[i]<<" ";
            ans+=arr[i]*(arr[i]+1)/2;
        }
        // cout<<endl;
        return ans;
    }
};