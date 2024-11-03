/**
 * Problem:
 *   https://leetcode.com/problems/rotate-string/description/
 * Solution:
 *   https://leetcode.com/problems/rotate-string/submissions/1441329482/
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
#include <string>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        // if their length is equal and s+s has goal
        return (s.length() == goal.length() &&
                (s + s).find(goal) != string::npos);
    }
};
