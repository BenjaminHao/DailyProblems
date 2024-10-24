/**
 * Problem: https://leetcode.com/problems/two-sum/description/
 * Solution: https://leetcode.com/problems/two-sum/submissions/1380477626
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
#include <unordered_map>  // using hash table to solve this problem
#include <vector>

class Solution
{
public:
    std::vector<int> twosum(std::vector<int> nums, int target)
    {
        // store numbers and thier indices into a hash table
        std::unordered_map<int, int> indices;
        // iterate nums vector
        for (int i = 0; i != nums.size(); ++i)
        {
            int complement = target - nums[i];
            // if the complement exists in the hash table
            if (indices.find(complement) != indices.end())
            {
                return {i, indices[nums[complement]]};
            }
            else
            {
                // we save current num into indices. key: num, value: index
                indices[nums[i]] = i;
            }
        }
        // if no result found, return {}
        return {};
    }
};
