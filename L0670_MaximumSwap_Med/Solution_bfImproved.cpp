/**
 * Problem:
 *   https://leetcode.com/problems/maximum-swap/description/
 * Solution:
 *   https://leetcode.com/problems/maximum-swap/submissions/1429778376/
 * Thought: iterate digits from right to left is better
 * Time complexity: O(n)
 * Space complexity: O(1) - couple ints, no string required
 */
#include <cmath>

class Solution
{
public:
    int maximumSwap(int num)
    {
        int max_val = -1, max_pos = -1;
        int l_val = -1, l_pos = -1;
        int r_val = -1, r_pos = -1;

        for (int i = 0, n = num; n; n /= 10, ++i)
        {
            int cur_val = n % 10;
            if (cur_val > max_val)
            {
                max_val = cur_val;
                max_pos = i;
            }
            else if (cur_val < max_val)
            {
                l_val = cur_val;
                l_pos = i;
                r_val = max_val;
                r_pos = max_pos;
            }
        }
        // How to swap digits:
        //  l r      l r
        //  ↓ ↓      ↓ ↓
        // 94283 -> 98243
        // 94283 -  4000  +  8000  +   40   -   80
        //  num  - l*10^3 + r*10^3 + l*10^1 - r*10^1
        //  num  - (l-r)*10^3      +    (l-r)*10^1
        //  num  - (l-r) * (10^3-10^1)
        int res = num - (l_val - r_val) *
                            (int)(std::pow(10, l_pos) - std::pow(10, r_pos));

        if (l_pos == -1)
            return num;
        else
            return res;
    }
};
