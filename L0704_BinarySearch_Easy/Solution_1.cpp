/**
 * Problem:
 *   https://leetcode.com/problems/binary-search/description/
 * Solution:
 *  https://leetcode.com/problems/binary-search/submissions/1436719232/
 * Thought:
 *   pay attention to bounds, left < right or left <= right?
 *   [Left, Right]
 * Time complexity: O(nlogn)
 * Space complexity: O(n)
 */
#include <vector>
using namespace std;

class Solution_1
{
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }

        return -1;
    }
};
