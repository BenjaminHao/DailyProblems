/**
 * Problem:
 *   https://leetcode.com/problems/coin-change/description/
 * Solution:
 *   https://leetcode.com/problems/coin-change/submissions/1430901904/
 * Thought:
 *   dp[i] - the min coins to make up amount i
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
        // note: can change INT_MAX to amount + 1;
        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i)
        {
            for (int coin : coins)
            {
                // if current coin is smaller than amount i
                // and the leftover amount can be made up by the coins
                if (i - coin >= 0 && dp[i - coin] != INT_MAX)
                {
                    // the min amount is dp[i] calculated before or
                    // use current coin + dp[leftover amount]
                    // depend on which is smaller
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        // if amount cannot be made up, return -1, or dp[amount]
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
