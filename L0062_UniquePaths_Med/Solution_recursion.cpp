/**
 * Problem:
 *   https://leetcode.com/problems/unique-paths/
 * Similar Questions: L0063 Unique Paths II
 * Solution: Time Limit Exceeded
 *   https://leetcode.com/problems/unique-paths/submissions/1425782356/
 * Time complexity: O(2^(m*n))
 * Space complexity: O(m*n)
 */
class Solution_recursion
{
public:
    int uniquePaths(int m, int n) { return path(m - 1, n - 1); }

private:
    int path(int i, int j)
    {
        if (i == 0 || j == 0)
            return 1;
        else if (i < 0 || j < 0)
            return 0;
        else
            return path(i, j - 1) + path(i - 1, j);
    }
};
