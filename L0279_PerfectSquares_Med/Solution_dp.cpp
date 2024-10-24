/**
 * Problem: (similar question: L0322 Coin Change)
 *   https://leetcode.com/problems/perfect-squares/description/
 * Solution:
 *   https://leetcode.com/problems/perfect-squares/submissions/1431826066/
 * Thought:
 *   dp[i] - the least number of perfect square numbers that sum to i
 * Time complexity: O(n * sqrt(n))
 * Space complexity: O(n)
 */
#include <algorithm>
#include <vector>

class Solution
{
public:
    int numSquares(int n)
    {
        // init value: n, because dp[i] <= n
        std::vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};
