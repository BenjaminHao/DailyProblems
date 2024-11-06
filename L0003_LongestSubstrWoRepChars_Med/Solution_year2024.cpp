/**
 * Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Solution: https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/1400114759
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <string>

class Solution_year2024 {
public:
    int lengthOfLongestSubstring(std::string s) {
      int result = 0;
      // 2 pointers
      int left = 0, right = 0;
      // hash table
      bool exist[256];
      memset(exist, false, sizeof(exist));

      while (right < s.size())
      {
        if (exist[s[right]])
        {
            exist[s[left]] = false;
            left++;
        }
        else
        {
            exist[s[right]] = true;
            right++;
        }
        result = (result > right - left ? result : right - left);
      }

      return result;
    }
};
