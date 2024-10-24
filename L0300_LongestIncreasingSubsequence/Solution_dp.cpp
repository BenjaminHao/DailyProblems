/**
 * Problem:
 *   https://leetcode.com/problems/longest-increasing-subsequence/description/
 * Solution:
 *   https://leetcode.com/problems/longest-increasing-subsequence/submissions/1423618056/
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 */
#include <algorithm>
#include <vector>

class Solution_dp
{
public:
    int lengthoflis(std::vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0) return 0;

        std::vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};
