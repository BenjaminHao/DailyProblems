/**
 * Problem:
 *   https://leetcode.com/problems/rotate-array/description/
 * Solution:
 *   https://leetcode.com/problems/rotate-array/submissions/1441423697/
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        k = k % nums.size();
        // 12345 -> 54321 (k = 2)
        reverse(nums.begin(), nums.end());
        // 54321 -> 45321 (k = 2), reverse is half-open range notation
        reverse(nums.begin(), nums.begin() + k);
        // 45321 -> 45123 (k = 2)
        reverse(nums.begin() + k, nums.end());
    }
};
