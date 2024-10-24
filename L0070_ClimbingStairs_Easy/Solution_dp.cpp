/**
 * Problem:
 *   https://leetcode.com/problems/climbing-stairs/description/
 * Solution:
 *   https://leetcode.com/problems/climbing-stairs/submissions/1423726871/
 * Thought: dp[i] - the distinct ways of climbing for stair i
     dp[i] = dp[i-1] + dp[i-2] since we can climb 1 step from dp[i-1] and 2
     steps from dp[i-2]
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
class Solution_recursion
{
public:
    int climbStairs(int n)
    {
        if (n == 1) return 1;

        int* dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i)
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }

        int res = dp[n];
        delete[] dp;
        return res;
    }
};
