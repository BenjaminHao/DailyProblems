/**
 * Problem:
 *   https://leetcode.com/problems/maximum-product-subarray/description/
 * Solution:
 *   https://leetcode.com/problems/maximum-product-subarray/submissions/1451923167/
 * Thought: Because there are negative ints, min product subarray is needed.
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int res = nums[0];
        int curMin = 1, curMax = 1;

        for (int num : nums)
        {
            if (num < 0) swap(curMax, curMin);
            curMax = max(num, num * curMax);
            curMin = min(num, num * curMin);
            res = max(res, curMax);
        }

        return res;
    }
};
