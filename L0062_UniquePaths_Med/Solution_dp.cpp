/**
 * Problem:
 *   https://leetcode.com/problems/unique-paths/
 * Similar Questions: L0063 Unique Paths II
 * Solution:
 *   https://leetcode.com/problems/unique-paths/submissions/1424732858/
 * Thought: dp[m][n] - unique paths that robot cn take
 *   dp[m][n] = dp[m-1][n] + dp[m][n-1];
 * Time complexity: O(m*n)
 * Space complexity: O(m*n)
 */
class Solution_dp
{
public:
    int uniquePaths(int m, int n)
    {
        // 2-dementional array in c++ may cause cache misses, use 1-d is enough
        // https://youtu.be/gNgUMA_Ur0U?si=X6Ig-mrVHX05Vok3
        int* dp = new int[m * n];
        dp[0] = 1;
        for (int i = 1; i < m; ++i)
        {
            dp[i] = 1;
        }
        for (int j = 1; j < n; ++j)
        {
            dp[j * m] = 1;
        }

        for (int y = 1; y < n; y++)
        {
            for (int x = 1; x < m; x++)
            {
                dp[x + y * m] = dp[(x - 1) + y * m] + dp[x + (y - 1) * m];
            }
        }

        int res = dp[(m - 1) + m * (n - 1)];
        delete[] dp;
        return res;
    }
};
