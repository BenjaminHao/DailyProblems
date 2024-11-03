/**
 * Problem:
 *   https://leetcode.com/problems/contains-duplicate/description/
 * Solution: TLE
 *   https://leetcode.com/problems/contains-duplicate/submissions/1441344926/
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */
#include <vector>
using namespace std;

class Solution_bf
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        for (int i = 0; i < nums.size() - 1; ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                if (nums[i] == nums[j]) return true;
        return false;
    }
};
