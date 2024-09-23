#include <string>

/**
 * Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Runtime: 0 ms, Beats 100.00%
 * Memory Usage: 10 MB, Beats 95.83%
**/
class Solution {
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
