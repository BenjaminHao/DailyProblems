/**
 * Problem:
 *   https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/
 * Solution:
 *   https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/submissions/1444123710/
 * Thought: we only need to compair the adjust 2 nums from the beginning,
 *   s[0]&s[1],s[2]&s[3]... if they are the same, the substring is beautiful.
 * Time complexity: O(n) Space complexity: O(1)
 */
#include <string>
using namespace std;

class Solution
{
public:
    int minChanges(string s)
    {
        int res = 0;

        for (int i = 1; i < s.length(); i += 2)
        {
            if (s[i] != s[i - 1]) res++;
        }

        return res;
    }
};
