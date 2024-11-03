/**
 * Problem:
 *   https://leetcode.com/problems/rotate-array/description/
 * Solution:
 *   https://leetcode.com/problems/rotate-array/submissions/1441423697/
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        vector<int> res(nums.size());

        for (int i = 0; i < nums.size(); ++i)
        {
            int pos = (i + k) % nums.size();
            res[pos] = nums[i];
        }

        nums = res;
    }
};
