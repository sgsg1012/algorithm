/* 
https://leetcode-cn.com/problems/minimized-maximum-of-products-distributed-to-any-store/

二分，太妙了吧  我TM用dp做的，太拉了 
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        auto check = [&](int mid)
        {
            int num = 0;
            for (auto q : quantities)
            {
                num += (q + mid - 1) / mid;
            }
            return num <= n;
        };
        int left = 1, right = 100100;
        while (left < right)
        {
            int mid = left + right >> 1;
            if (check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
int main()
{
}
