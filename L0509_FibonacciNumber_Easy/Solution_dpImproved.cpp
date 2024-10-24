/**
 * Problem:
 *   https://leetcode.com/problems/fibonacci-number/description/
 * Solution:
 *   https://leetcode.com/problems/fibonacci-number/submissions/1423708459/
 * Thought: dp[i] only relys on dp[i - 1] and dp[i - 2], 3 variables are enough
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
class Solution_dpImproved
{
public:
    int fib(int n)
    {
        int left = 0;
        if (n == 0) return left;
        int right = 1;
        if (n == 1) return right;
        int sum = 0;
        for (int i = 2; i <= n; ++i)
        {
            // 0 1 1 2 3 5 8 13...
            sum = left + right;
            left = right;
            right = sum;
        }

        return sum;
    }
};
