/**
 * Problem:
 *   https://leetcode.com/problems/climbing-stairs/description/
 * Solution: (Time Limit Exceeded)
 *   https://leetcode.com/problems/climbing-stairs/submissions/1423717502/
 * Time complexity: O(2^n)
 * Space complexity: O(n)
 */
class Solution_recursion
{
public:
    int climbStairs(int n)
    {
        if (n == 0) return 0;
        if (n == 1) return 1;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
