/**
 * Problem:
 *   https://leetcode.com/problems/majority-element/description/
 * Solution:
 *   https://leetcode.com/problems/majority-element/submissions/1464781468/
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> frequency;

        for (int num : nums)
        {
            frequency[num]++;
            if (frequency[num] > nums.size() / 2) return num;
        }

        return -1;
    }
};
