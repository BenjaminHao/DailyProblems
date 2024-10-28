/**
 * Problem:
 *   https://leetcode.com/problems/teemo-attacking/description/
 * Solution:
 *   https://leetcode.com/problems/teemo-attacking/submissions/1433635737/
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
#include <vector>

class Solution
{
public:
    int findPoisonedDuration(std::vector<int>& timeSeries, int duration)
    {
        int res = 0;

        for (int i = 1; i < timeSeries.size(); ++i)
        {
            int curr = timeSeries[i];
            int last = timeSeries[i - 1];

            // if 2 attacks duration longer than poison duration
            if (curr - last >= duration) res += duration;
            // shorter - just add attacks duration
            else
                res += (curr - last);
        }

        // the last attack needs to do dmg
        return res + duration;
    }
};
