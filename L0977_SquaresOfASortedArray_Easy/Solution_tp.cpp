/**
 * Problem:
 *   https://leetcode.com/problems/squares-of-a-sorted-array/description/
 * Solution:
 *   https://leetcode.com/problems/squares-of-a-sorted-array/submissions/1442246290/
 * Thought:
 *   After squaring, the biggest elements must be at the beginning or end of
 *   the new array, use two pointers at the beginning & the end.
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> res(nums.size());
        int i = 0, j = nums.size() - 1, k = nums.size() - 1;

        while (i <= j)
        {
            if (nums[i] * nums[i] > nums[j] * nums[j])
            {
                res[k--] = nums[i] * nums[i];
                ++i;
            }
            else
            {
                res[k--] = nums[j] * nums[j];
                --j;
            }
        }

        return res;
    }
};
