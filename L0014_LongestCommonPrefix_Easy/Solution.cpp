/**
 * Problem:
 *   https://leetcode.com/problems/longest-common-prefix/description/
 * Solution:
 *   https://leetcode.com/problems/longest-common-prefix/submissions/1444544174/
 * Time Complexity: O(N^L) where N is the size of strs, L is the length of str
 * Space Complexity: O(1)
 */

#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string res = "";

        for (int i = 0; i < strs[0].length(); ++i)
        {
            char tmp = strs[0][i];
            bool isCommon = true;
            for (int j = 1; j < strs.size(); ++j)
            {
                if (!strs[j][i] || strs[j][i] != tmp)
                {
                    isCommon = false;
                    break;
                }
            }
            if (isCommon)
                res += tmp;
            else
                break;
        }

        return res;
    }
};
