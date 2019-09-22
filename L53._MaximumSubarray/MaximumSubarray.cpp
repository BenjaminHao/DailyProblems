#include <vector>
#include <algorithm>

/** Maximum Subarray: https://leetcode.com/problems/maximum-subarray/
 *  Dynamic Programming
 *  Runtime: 4 ms, faster than 98.60% of C++ online submissions for Maximum Subarray.
 *  Memory Usage: 9.3 MB, less than 69.61% of C++ online submissions for Maximum Subarray.
**/
class Solution 
{
public:
    int maxSubArray(std::vector<int>& nums) 
    {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        int res = nums[0];
        int* dp = new int[nums.size()]; 
        dp[0] = nums[0];

        for (int i = 1; i != nums.size(); ++i)
        {
            if (dp[i - 1] > 0)
            {
                dp[i] = dp[i - 1] + nums[i];
            }
            else
            {
                dp[i] = nums[i];
            }
            res = std::max(res, dp[i]);
        }
        return res;
    }
};