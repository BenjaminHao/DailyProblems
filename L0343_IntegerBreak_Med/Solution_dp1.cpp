/**
 * Problem:
 *   https://leetcode.com/problems/integer-break/description/
 * Solution:
 *   https://leetcode.com/problems/integer-break/submissions/1430807253/
 * Thought:
 *   dp[i] - the max product after breaking integer i
 *   dp[i] = max(dp[i],j*(i-j),j*dp[i-j]) - 3 cases: no breaking, breaking
 *     into 2 parts, breaking into 3 or more parts.
 *   Why j*dp[i-j] instead of dp[j]*dp[i-j]? - dp[i-j] already includes dp[j]
 *     also dp[j]*dp[i-j] means breaking into at least 4 parts, missing 3 parts
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
        std::vector<int> dp(n + 1);
        dp[0] = 0;  // cant break 0
        dp[1] = 0;  // cant break 1

        // starting from 2
        for (int i = 2; i <= n; ++i)
        {
            // j<=i/2 - remove duplicates, the other half is the same
            for (int j = 1; j <= i / 2; ++j)
            {
                dp[i] = std::max({dp[i], j * (i - j), j * dp[i - j]});
            }
        }

        return dp[n];
    }
};
