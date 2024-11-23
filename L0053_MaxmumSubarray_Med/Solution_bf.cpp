/**
 * Problem:
 *   https://leetcode.com/problems/maximum-subarray/description/
 * Solution: Time Limit Exceeded
 *   https://leetcode.com/problems/maximum-subarray/submissions/1460384579/
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j)
            {
                sum += nums[j];
                res = max(res, sum);
            }
        }
        return res;
    }
};
