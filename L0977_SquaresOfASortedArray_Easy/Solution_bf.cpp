/**
 * Problem:
 *   https://leetcode.com/problems/squares-of-a-sorted-array/description/
 * Solution:
 *   https://leetcode.com/problems/squares-of-a-sorted-array/submissions/1442238963/
 * Time complexity: O(nlogn)
 * Space complexity: O(n)
 */
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); ++i) res[i] = nums[i] * nums[i];
        sort(res.begin(), res.end());
        return res;
    }
};
