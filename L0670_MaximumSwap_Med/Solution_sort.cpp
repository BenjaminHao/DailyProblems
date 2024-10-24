/**
 * Problem:
 *   https://leetcode.com/problems/maximum-swap/description/
 * Solution:
 *   https://leetcode.com/problems/maximum-swap/submissions/1426810585/
 * Thought: Compair num and the maximum num after multiple swapping
 *   the first different digits are the digits to be swapped
 * Time complexity: O(nlog(n)) worst: O(n)
 * Space complexity: O(1)
 */

#include <algorithm>
#include <string>

class Solution_sort
{
public:
    int maximumSwap(int num)
    {
        // str:  99346562
        // sort: 99665432
        std::string str = std::to_string(num);
        std::string str_sorted = str;
        std::sort(str_sorted.rbegin(), str_sorted.rend());

        // find the different pos
        int i = 0;
        while (i < str.size() && str[i] == str_sorted[i]) ++i;
        // return if it's already the biggest
        if (i == str.size()) return num;

        int r_swap = -1;
        for (int j = i + 1; j < str.size(); ++j)
        {
            // find the last occured pos of different digit in str
            if (str[j] == str_sorted[i]) r_swap = j;
        }

        std::swap(str[i], str[r_swap]);
        return std::stoi(str);
    }
};
