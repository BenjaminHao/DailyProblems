/**
 * Problem: https://leetcode.com/problems/two-sum/description/
 * Solution: https://leetcode.com/problems/two-sum/submissions/1380471103
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */
#include <vector>

class Solution_bruteForce
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
