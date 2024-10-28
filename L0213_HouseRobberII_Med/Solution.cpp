/**
 * Problem: similar: House Robber III
 *   https://leetcode.com/problems/house-robber-ii/description/
 * Solution:
 *   https://leetcode.com/problems/house-robber-ii/submissions/1436549689/
 * Thought:
 *   Because it's a ring, we can get rid of the last element, or the first
 *   element, to make it become liner question. i.e. 1. don't rob first house.
 *   2. don't rob last house
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(), 0);

        // don't rob the last house, check the second last
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size() - 1; ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int res1 = dp[nums.size() - 2];

        // don't rob the first house, check the last
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int res2 = dp[nums.size() - 1];

        return max(res1, res2);
    }
};
