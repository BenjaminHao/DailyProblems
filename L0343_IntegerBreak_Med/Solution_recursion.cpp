/**
 * Problem:
 *   https://leetcode.com/problems/integer-break/description/
 * Solution: Time Limit Exceeded
 *   https://leetcode.com/problems/integer-break/submissions/1429808496/
 * Time complexity: O(2^n)
 * Space complexity: O(n)
 */
#include <algorithm>

class Solution_recursion
{
public:
    int integerBreak(int n) { return dfs(n); }

private:
    int dfs(int n)
    {
        if (n == 1) return 1;
        int res = 0;

        for (int i = 1; i < n; i++)
        {
            res = std::max({res, i * (n - i), i * dfs(n - i)});
        }
        return res;
    }
};
