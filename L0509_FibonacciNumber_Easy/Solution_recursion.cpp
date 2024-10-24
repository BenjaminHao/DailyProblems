/**
 * Problem:
 * https://leetcode.com/problems/fibonacci-number/description/
 * Solution:
 * https://leetcode.com/problems/fibonacci-number/submissions/1423658579/
 * Time complexity: O(2^n)
 * Space complexity: O(n)
 */
class Solution_recursion
{
public:
    int fib(int n)
    {
        // base cases
        if (n == 0) return 0;
        if (n == 1) return 1;
        // recursive case
        return fib(n - 1) + fib(n - 2);
    }
};
