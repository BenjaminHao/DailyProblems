/**
 * Problem:
 *   https://leetcode.com/problems/target-sum/description/
 * Solution:
 *
 * Thought:
 *   dp[i] - the different expressions built to equal to i
 *   How to get different expressions?
 *     devide nums into two parts: left+right=sum, left-right=target,
 *     right = sum-left, left-(sum-left)=target -> left=(target+sum)/2
 * Time complexity: O(amount * len(coins))
 * Space complexity: O(amount)
 */
#include <vector>

class Solution
{
public:
    int findTargetSumWays(std::vector<int>& nums, int target)
    {
        // TODO: solve this
        return 0;
    }
};
