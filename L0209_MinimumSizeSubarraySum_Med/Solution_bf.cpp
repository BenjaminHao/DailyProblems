/**
 * Problem:
 *   https://leetcode.com/problems/minimum-size-subarray-sum/description/
 * Solution: TLE
 *   https://leetcode.com/problems/minimum-size-subarray-sum/submissions/1442262173/
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */
#include <vector>
using namespace std;

class Solution_bf
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int res = nums.size() + 1;

        for (int i = 0; i < nums.size(); ++i)
        {
            int curSum = nums[i];
            if (curSum >= target) return 1;
            int curLen = 1;

            for (int j = i + 1; j < nums.size(); ++j)
            {
                curSum += nums[j];
                if (curSum < target)
                    curLen++;
                else
                {
                    res = min(res, curLen + 1);
                    break;  // looking the shortest, just break if found
                }
            }
        }

        if (res == nums.size() + 1)
            return 0;
        else
            return res;
    }
};
