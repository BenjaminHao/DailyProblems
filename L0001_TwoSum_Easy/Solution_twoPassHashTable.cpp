/**
 * Problem: https://leetcode.com/problems/longest-palindromic-substring/description/
 * Solution: https://leetcode.com/problems/two-sum/submissions/1384732243
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
#include <vector>
#include <unordered_map> // using hash table to solve this problem

class Solution_twoPassHashTable
{
public:
    std::vector<int> twosum(std::vector<int> nums, int target)
    {
        std::unordered_map<int, int> indices;
        // Create hash table, key: num elements, val: indices
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]] = i;
        }
        // Look for complement
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (indices.count(complement) && indices[complement] != i)
            {
                return {i, indices[complement]};
            }
        }
        return {};
    }
};
