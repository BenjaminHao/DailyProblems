/**
 * Problem:
 *   https://leetcode.com/problems/valid-parentheses/description/
 * Solution:
 *   https://leetcode.com/problems/valid-parentheses/submissions/1441409405/
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        // if string has odd size, must not valid
        if (s.size() % 2 != 0) return false;

        stack<char> stack;

        for (char c : s)
        {
            if (c == '(')
                stack.push(')');
            else if (c == '[')
                stack.push(']');
            else if (c == '{')
                stack.push('}');
            // if put )]} first or didnt close {[(
            else if (stack.empty() || stack.top() != c)
                return false;
            // if closed, we get rid of parentheses
            else
                stack.pop();
        }
        // if parentheses are still not closed, return false;
        // if all closed, return true
        return stack.empty();
    }
};
