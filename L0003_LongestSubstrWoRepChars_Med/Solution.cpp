/**
 * Problem:
 *   https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Solution:
 *   https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/1464640198/
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> seen;
        int res = 0, left = 0, right = 0;

        while (right < s.length())
        {
            if (seen.insert(s[right]).second)
                right++;
            else
            {
                seen.erase(s[left]);
                left++;
            }
            res = max(res, right - left);
        }

        return res;
    }
};
