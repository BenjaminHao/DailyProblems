/**
 * Problem:
 *   https://leetcode.com/problems/sqrtx/description/
 * Solution:
 *   https://leetcode.com/problems/sqrtx/submissions/1441311156/
 * Time complexity: O(logn)
 * Space complexity: O(1)
 */
class Solution_bs
{
public:
    int mySqrt(int x)
    {
        if (x <= 1) return x;
        int left = 1, right = x, res;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid < x / mid)
                left = mid + 1;
            else if (mid > x / mid)
            {
                right = mid - 1;
                res = mid - 1;
            }
            else
                return mid;
        }
        return res;
    }
};
