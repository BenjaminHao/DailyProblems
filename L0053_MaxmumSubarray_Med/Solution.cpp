/**
 * Problem:
 *   https://leetcode.com/problems/maximum-subarray/description/
 * Solution:
 *   https://leetcode.com/problems/maximum-subarray/submissions/1460385512/
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int res = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            res = max(res, sum);

            // as long as sum is negative, we start counting at the next num
            // as it only makes the next sum smaller
            if (sum < 0) sum = 0;
        }
        return res;
    }
};
