/**
 * Problem:
 *   https://leetcode.com/problems/target-sum/description/
 * Solution:
 *   https://leetcode.com/problems/target-sum/submissions/1432891760/
 * Time complexity: O(2^n)
 * Space complexity: O(n)
 */
#include <vector>

// TODO: Revisit this
class Solution
{
public:
    int res = 0;
    int findTargetSumWays(std::vector<int>& nums, int target)
    {
        dfs(nums, 0, target, 0);
        return res;
    }

private:
    void dfs(std::vector<int>& nums, int start, int target, int curr)
    {
        int res = 0;
        if (start == nums.size())
        {
            if (target == curr) ++res;
            return;
        }

        dfs(nums, start + 1, target, curr + nums[start]);
        dfs(nums, start + 1, target, curr - nums[start]);
    }
};
