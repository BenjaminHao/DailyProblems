#include <vector>
#include <unordered_map> // using hash table to solve this problem

/**
 * Problem: https://leetcode.com/problems/two-sum/
 * Runtime: 3ms. Memory usage: 16.1MB
**/
class Solution
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
