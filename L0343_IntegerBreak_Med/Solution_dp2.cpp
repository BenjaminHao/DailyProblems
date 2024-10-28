/**
 * Problem:
 *   https://leetcode.com/problems/integer-break/description/
 * Solution:
 *   https://leetcode.com/problems/integer-break/submissions/1433726187/
 * Thought:
 *   dp[i] - the max product after breaking integer i if need to break
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 */
#include <algorithm>
#include <vector>

class Solution_dp1
{
public:
    int integerBreak(int n)
    {
        if (n <= 2) return 1;
        if (n == 3) return 2;

        std::vector<int> dp(n + 1, 0);
        // don't need to break 1, 2, 3
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for (int i = 4; i <= n; ++i)
        {
            for (int j = 1; j <= i / 2; ++j)
            {
                dp[i] = std::max(dp[i], dp[j] * dp[i - j]);
            }
        }

        return dp[n];
    }
};
