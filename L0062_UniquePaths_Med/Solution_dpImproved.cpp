/**
 * Problem:
 *   https://leetcode.com/problems/unique-paths/
 * Similar Questions: L0063 Unique Paths II
 * Solution:
 *   https://leetcode.com/problems/unique-paths/submissions/1425801107/
 * Thought: we actually only need to store 1 row/column of data
 * Time complexity: O(m*n)
 * Space complexity: O(m) or O(n), O(n) in this case
 */
#include <algorithm>

class Solution_dpimproved
{
public:
    int uniquePaths(int m, int n)
    {
        int res;
        int* dp = new int[n];
        std::fill(dp, dp + n, 1);

        for (int i = 1; i < m; ++i)
        {
            int PrevColumn = 1;
            for (int j = 1; j < n; ++j)
            {
                dp[j] += PrevColumn;
                PrevColumn = dp[j];
            }
        }
        res = dp[n - 1];
        return res;
    }
};
