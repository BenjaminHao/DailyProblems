/**
 * Problem:
 *   https://leetcode.com/problems/coin-change/description/
 * Solution:
 *   https://leetcode.com/problems/coin-change/submissions/1430919412/
 * Thought:
 *   same as Solution_dp1, this iterates through coins first
 *   dp[j] - the min coins to make up amount j
 * Time complexity: O(amount * len(coins))
 * Space complexity: O(amount)
 */
#include <climits>
#include <vector>

class Solution
{
public:
    int coinChange(std::vector<int>& coins, int amount)
    {
        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        // iterate through coins
        for (int i = 0; i < coins.size(); ++i)
        {
            // iterate through amount
            for (int j = coins[i]; j <= amount; ++j)
            {
                // if leftover amount can be made up by coins
                if (dp[j - coins[i]] != INT_MAX)
                {
                    dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
