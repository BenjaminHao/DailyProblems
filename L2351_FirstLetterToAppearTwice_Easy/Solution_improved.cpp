/**
 * Problem:
 *   https://leetcode.com/problems/first-letter-to-appear-twice/description/
 * Solution:
 *   https://leetcode.com/problems/first-letter-to-appear-twice/submissions/1445146268/
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
#include <algorithm>
#include <string>
using namespace std;

class Solution_improved
{
public:
    char repeatedCharacter(string s)
    {
        bool seen[26];
        fill(seen, seen + 26, false);
        char res;
        for (int i = 0; i < s.length(); ++i)
        {
            if (seen[s[i] - 'a'])
            {
                res = s[i];
                break;
            }
            else
                seen[s[i] - 'a'] = true;
        }

        return res;
    }
};
