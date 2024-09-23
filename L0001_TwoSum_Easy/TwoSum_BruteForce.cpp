#include <vector>

/**
 * Problem: https://leetcode.com/problems/two-sum/
 * Runtime: 53ms. Memory usage: 12.9MB O(n^2)
**/
class Solution
{
public:
    std::vector<int> twosum(std::vector<int> nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
};
