/**
 * Problem:
 *   https://leetcode.com/problems/unique-paths-ii/
 * Similar Questions: L0062 Unique Paths
 * Solution:
 *   https://leetcode.com/problems/unique-paths-ii/submissions/1425820035/
 * Thought: dp[m][n] - unique paths that robot cn take
 *   dp[m][n] = dp[m-1][n] + dp[m][n-1] if no obstacle, otherwise 0;
 *   base condition - if obstacle at edge, all tiles after are unreachable
 * Time complexity: O(m * n)
 * Space complexity: O(m * n)
 */
#include <vector>

class Solution_dp
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        for (int i = 0; i < m; ++i)
        {
            // if there's an obstacle, all paths bellow are unreachable
            if (obstacleGrid[i][0] == 1)
                break;
            else
                dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j)
        {
            // if there's an obstacle, all paths forward are unreachable
            if (obstacleGrid[0][j] == 1)
                break;
            else
                dp[0][j] = 1;
        }

        for (int y = 1; y < m; ++y)
        {
            for (int x = 1; x < n; ++x)
            {
                if (obstacleGrid[y][x] == 1)
                    dp[y][x] = 0;
                else
                    dp[y][x] = dp[y - 1][x] + dp[y][x - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
