/**
 * Problem:
 *   https://leetcode.com/problems/sqrtx/description/
 * Solution:
 *   https://leetcode.com/problems/sqrtx/submissions/1441302208/
 * Time complexity: O(sqrt(n))
 * Space complexity: O(1)
 */
class Solution_bf
{
public:
    int mySqrt(int x)
    {
        if (x <= 1) return x;
        for (int i = 1; i <= x; ++i)
        {
            if (i > x / i) return i - 1;
        }
        return -1;
    }
};
