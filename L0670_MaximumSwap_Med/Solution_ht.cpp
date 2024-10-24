/**
 * Problem:
 *   https://leetcode.com/problems/maximum-swap/description/
 * Solution:
 *   https://leetcode.com/problems/maximum-swap/submissions/1426791046/
 * Thought: the idea is swap the smallest most significant digit with
 *   the biggest most insignificnat digit
 * Time complexity: O(n)
 * Space complexity: O(1) - array to store 10 digits
 */
#include <algorithm>
#include <string>

class Solution_ht
{
public:
    int maximumSwap(int num)
    {
        int lastOccur[10];
        std::fill(lastOccur, lastOccur + 10, -1);

        std::string str = std::to_string(num);

        for (int i = 0; i < str.length(); ++i)
        {
            // store its last occurrence - also its most insignificant postion
            lastOccur[str[i] - '0'] = i;
        }

        for (int i = 0; i < str.length(); ++i)
        {
            // find digits that bigger than current, from 9 to current
            for (int j = 9; j > str[i] - '0'; --j)
            {
                // if the biggest most insignificant digit is after current pos
                if (lastOccur[j] > i)
                {
                    // just swap these two and return
                    std::swap(str[i], str[lastOccur[j]]);
                    return std::stoi(str);
                }
            }
        }
        // no need to swap
        return num;
    }
};
