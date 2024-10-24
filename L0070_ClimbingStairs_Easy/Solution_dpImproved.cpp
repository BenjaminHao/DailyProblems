/**
 * Problem:
 *   https://leetcode.com/problems/climbing-stairs/description/
 * Solution:
 *   https://leetcode.com/problems/climbing-stairs/submissions/1423861104/
 * Thought: we only need 3 variables to maintain
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
class Solution_recursion
{
public:
    int climbStairs(int n)
    {
        // init variables, secondLastStair is stair 1, lastStair is stair 2
        int secondLastStair = 1, lastStair = 2;
        if (n == 1) return secondLastStair;
        if (n == 2) return lastStair;

        int steps;
        for (int i = 3; i <= n; ++i)
        {
            // new distinct ways
            steps = secondLastStair + lastStair;
            // move to next stair
            secondLastStair = lastStair;
            lastStair = steps;
        }
        return steps;
    }
};
