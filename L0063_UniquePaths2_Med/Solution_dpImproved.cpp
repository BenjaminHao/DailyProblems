/**
 * Problem:
 *   https://leetcode.com/problems/unique-paths-ii/
 * Similar Questions: L0062 Unique Paths
 * Solution:
 *   https://leetcode.com/problems/unique-paths-ii/submissions/1425837841/
 * Thought: same as L0062, we only need store the data of a single row/column
 * Time complexity: O(m*n)
 * Space complexity: O(m) or O(n), O(n) in this case
 */
#include <vector>

class Solution_dp
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // if there's an obstacle
                if (obstacleGrid[i][j] == 1)
                    // no paths through
                    dp[j] = 0;
                else if (j > 0)
                    // ↓NewRow ↓LastRow  ↓leftside
                    dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
