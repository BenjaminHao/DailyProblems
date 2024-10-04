/**
 * Problem: https://leetcode.com/problems/longest-palindromic-substring/description/
 * Solution: https://leetcode.com/problems/longest-palindromic-substring/submissions/1409905084
 * Time Complexity: O(N^3)
 * Space Complexity: O(1)
 */
#include <string>

class Solution_bruteForce {
public:
    std::string longestPalindrome(std::string s) {
        int maxLen = 1, startPos = 0;

        for (int i = 0; i < s.size() - 1; ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                if (j - i + 1 > maxLen && isPalindrome(s, i, j)) {
                    maxLen = j - i + 1;
                    startPos = i;
                }
            }
        }
        return s.substr(startPos, maxLen);
    }
private:
    bool isPalindrome(const std::string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
