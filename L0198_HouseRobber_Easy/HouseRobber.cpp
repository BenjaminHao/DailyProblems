#include <vector>
#include <algorithm>

/** House Robber: https://leetcode.com/problems/house-robber/
 * Dynamic programming
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
 * Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for House Robber.
**/
class Solution
{
public:
    int rob(std::vector<int>& nums)
    {
        if (nums.size() == 0) return 0;

        int* dp = new int[nums.size() + 1]; // Why nums.size() + 1? We make the index of dp be the house's number.
        dp[0] = 0;  // the 0'th house - does not exist. 
        dp[1] = nums[0]; // the first house, which is nums[0]

        for (int i = 2; i <= nums.size(); ++i) // from house #2 to last house
        {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]); // nums[i - 1] is the value of i'th house
        }

        return dp[nums.size()]; // nums.size() is the totoal amount of houses.
    }
};
