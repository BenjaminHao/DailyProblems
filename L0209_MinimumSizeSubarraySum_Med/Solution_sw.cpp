/**
 * Problem:
 *   https://leetcode.com/problems/minimum-size-subarray-sum/description/
 * Solution:
 *   https://leetcode.com/problems/minimum-size-subarray-sum/submissions/1442287461/
 * Thought:
 *   Using sliding window technical
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
#include <vector>
using namespace std;

class Solution_sw
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int i = 0, res = nums.size() + 1;

        int sum = 0;
        for (int j = 0; j < nums.size(); ++j)
        {
            sum += nums[j];
            while (sum >= target)
            {
                int curLen = j - i + 1;
                res = min(res, curLen);
                sum -= nums[i];
                ++i;
            }
        }

        return res == nums.size() + 1 ? 0 : res;
    }
};
