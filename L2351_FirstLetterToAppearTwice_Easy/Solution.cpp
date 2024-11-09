/**
 * Problem:
 *   https://leetcode.com/problems/first-letter-to-appear-twice/description/
 * Solution:
 *   https://leetcode.com/problems/first-letter-to-appear-twice/submissions/1445136140/
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        unordered_set<char> seen;
        char res;
        for (int i = 0; i < s.length(); ++i)
        {
            res = s[i];
            if (!seen.insert(res).second) break;
        }

        return res;
    }
};
