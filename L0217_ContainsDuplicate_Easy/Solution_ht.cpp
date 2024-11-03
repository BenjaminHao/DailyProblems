/**
 * Problem:
 *   https://leetcode.com/problems/contains-duplicate/description/
 * Solution:
 *   https://leetcode.com/problems/contains-duplicate/submissions/1441350733/
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
#include <unordered_set>
#include <vector>
using namespace std;

class Solution_bf
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (seen.find(nums[i]) != seen.end())
                return true;
            else
                seen.insert(nums[i]);

            // OR if (!seen.insert(nums[i]).second) return true;
        }
        return false;
    }
};
