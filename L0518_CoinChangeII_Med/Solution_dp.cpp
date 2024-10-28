/**
 * Problem:
 *   https://leetcode.com/problems/coin-change-ii/description/
 * Solution:
 *  https://leetcode.com/problems/coin-change-ii/submissions/1431922198/
 * Thought:
 *   dp[i] - the combinations to make up amount i
 * Note:
 *   can only iterate coins, since iterate amount will cause duplicate result
 * Time complexity: O(amount * len(coins))
 * Space complexity: O(amount)
 */
#include <vector>

class Solution
{
public:
    int change(int amount, std::vector<int>& coins)
    {
        std::vector<int> dp(amount + 1, 0);
        // Base case: there's one way to make amount 0 (using no coins)
        // makes no sense to me, in coin change 1, dp[0] = 0
        dp[0] = 1;

        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};
