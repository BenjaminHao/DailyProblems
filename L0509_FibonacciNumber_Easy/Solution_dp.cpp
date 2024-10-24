/**
 * Problem:
 *   https://leetcode.com/problems/fibonacci-number/description/
 * Solution:
 *   https://leetcode.com/problems/fibonacci-number/submissions/1423682818/
 * Thought: dp[i] - the i'th fibonacci-number
 *   dp[0] = 0, dp[1] = 1, dp[i] = dp[i - 1] + dp[i - 2]
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
class Solution_dp
{
public:
    int fib(int n)
    {
        if (n == 0) return 0;
        int* dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int res = dp[n];
        delete[] dp;
        return res;
    }
};
