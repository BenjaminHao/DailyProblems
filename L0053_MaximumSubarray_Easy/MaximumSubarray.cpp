#include <vector>
#include <algorithm>

/** Maximum Subarray: https://leetcode.com/problems/maximum-subarray/
 *  DP Easier approach
 *  Runtime: 8 ms, faster than 71.42% of C++ online submissions for Maximum Subarray.
 *  Memory Usage: 9.3 MB, less than 67.65% of C++ online submissions for Maximum Subarray.
**/
class Solution 
{
public:
    int maxSubArray(std::vector<int>& nums) 
    {
        int curSum = 0, res = INT_MIN;

        for (int num : nums)
        {
            curSum += num;
            res = std::max(curSum, res);
            if (curSum < 0) curSum = 0;
        }

        return res;
    }
};