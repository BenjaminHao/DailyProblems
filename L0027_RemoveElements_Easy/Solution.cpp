/**
 * Problem:
 *   https://leetcode.com/problems/remove-element/description/
 * Solution:
 *   https://leetcode.com/problems/remove-element/submissions/215808790/
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        // 2 pointers
        int j = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val)
            {
                nums[j] = nums[i];
                ++j;
            }
        }
        return j;
    }
};
