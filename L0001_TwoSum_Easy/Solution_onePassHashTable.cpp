/**
 * Problem: https://leetcode.com/problems/two-sum/description/
 * Solution: https://leetcode.com/problems/two-sum/submissions/1380477626
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
#include <vector>
#include <unordered_map> // using hash table to solve this problem

class Solution
{
public:
    std::vector<int> twosum(std::vector<int> nums, int target)
    {
        std::unordered_map<int, int> indices; // store numbers and thier indices into a hash table

        for (int i = 0; i != nums.size(); ++i) // iterate nums vector
        {
            int complement = target - nums[i];

            if (indices.find(complement) != indices.end()) // if the complement exists in the hash table
            {
                return {i, indices[nums[complement]]};
            }
            else // if the complement does not exist
            {
                indices[nums[i]] = i; // we save current num into indices. key: num, value: index
            }
        }

        return {}; //if no result found, return {}
    }
};
