/**
 * Solution: https://leetcode.com/problems/longest-palindromic-substring/submissions/1410993838
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 * Thinking:
 *   if s[l~r] is a palindrome, s[l+1~r-1] is also one
 *   if s[l~r] is not a palindrome, s[l-1~r+1] is not, either
 *   e.g. aBCDa, BCD is not a palindrome, aBCDa cannot be one, either
 *   So instead of starting from two sides, we can start from the center and expand
 *   if dp[l + 1][r - 1] and s[l] == s[r]: dp[l][r] = true
 */
#include <algorithm>
#include <string>

class Solution_dp
{
public:
    std::string longestPalindrome(std::string s)
    {
        int maxLen = 1, startPos = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            int curLen = std::max(getPalindromeLen(s, i, i), getPalindromeLen(s, i, i + 1)); // even and odd case
            if (curLen > maxLen)
            {
                maxLen = curLen;
                startPos = i - (maxLen - 1) / 2;
            }
        }
        return s.substr(startPos, maxLen);
    }
private:
    int getPalindromeLen(const std::string& s, int l, int r)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            --l;
            ++r;
        }
        return r - l - 1; // extra run in while loop, length should -2: r-l+1-2
    }
};

