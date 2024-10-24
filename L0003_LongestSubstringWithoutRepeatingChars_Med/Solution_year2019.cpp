/**
 * Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Solution: https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/262094594
 * Runtime: 12 ms, faster than 82.16%
 * Memory Usage: 9.1 MB, less than 97.01%
 */
#include <string>
#include <algorithm>

class Solution_year2019
{
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        int res = 0; // result, the value we return
        int begin = 0, end = 0; // two pointers, to track the distance between two values
        int arr[256]; // hash tbale, since char is also a integral type, we can simply use an array. (key: index, value: 0 or 1)
        memset(arr, 0, sizeof(arr)); // set elements of array to 0

        while (end != s.size()) // iterate the string
        {
            if (arr[s[end]] != 0) // if the character already exists
            {
                --arr[s[begin]]; // remove the existing character from hash table
                ++begin; // move begin pointer to the next character
            }
            else // if the character does not exist
            {
                ++arr[s[end]]; // add the character to hash table
                ++end; // move end pointer to the next character
            }
            res = std::max(res, end - begin); // make sure we return the max value
        }
        return res;
    }
};
