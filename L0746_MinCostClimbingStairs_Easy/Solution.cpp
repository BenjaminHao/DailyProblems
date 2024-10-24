/**
 * Problem:
 *   https://leetcode.com/problems/min-cost-climbing-stairs/description/
 * Similar Questions: L0070 Climbing Chairs
 * Solution:
 *   https://leetcode.com/problems/min-cost-climbing-stairs/submissions/1424684485/
 * Thought: dp[i] - the costs of climbing for stair i,
 *   dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
#include <vector>

class Solution
{
public:
    int minCostClimbingStairs(std::vector<int>& cost)
    {
        int n = cost.size();
        std::vector<int> dp(n + 1);  // need extra stair for the top
        dp[0] = 0;
        dp[1] = 0;  // you can either start from step with index 0 or 1

        for (int i = 2; i <= n; ++i)
        {
            dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};
