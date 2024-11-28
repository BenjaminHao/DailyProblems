/**
 * Problem:
 *   https://leetcode.com/problems/majority-element/description/
 * Solution:
 *   https://leetcode.com/problems/majority-element/submissions/1464793721/
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int res = 0, occur = 0;

        for (int num : nums)
        {
            if (occur == 0) res = num;
            if (res == num)
                occur++;
            else
                occur--;
        }
        return res;
    }
};
