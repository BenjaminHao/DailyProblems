/**
 * Problem:
 *   https://leetcode.com/problems/longest-increasing-subsequence/description/
 * Solution:
 *   https://leetcode.com/problems/longest-increasing-subsequence/submissions/1436691568/
 * Thought:
 *   dp[i] - the smallest ending number of a subsequence that has lengh i+1.
 *   For each num, we can
 *   1. extend the longest subsequence
 *   2. replace a number to generate a better subsequence
 * Time complexity: O(nlogn)
 * Space complexity: O(n)
 */
#include <algorithm>
#include <vector>
using namespace std;

class Solution_binarySearch
{
public:
    int lengthoflis(vector<int>& nums)
    {
        vector<int> dp;

        for (int num : nums)
        {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end())
                dp.push_back(num);
            else
                *it = num;

            // OR
            // if (dp.empty() || dp.back() < num)
            //     dp.push_back(num);
            // else
            //     *lower_bound(dp.begin(), dp.end(), num) = num;
        }
        return dp.size();
    }
};
