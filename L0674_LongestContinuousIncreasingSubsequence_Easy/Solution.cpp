/**
 * Problem:
 *   https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
 * Solution:
 *   https://leetcode.com/problems/longest-continuous-increasing-subsequence/submissions/1436581842/
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        if (nums.size() == 0) return 0;

        int res = 1;
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = max(dp[i], dp[i - 1] + 1);
                res = max(dp[i], res);
            }
        }

        return res;
    }
};
