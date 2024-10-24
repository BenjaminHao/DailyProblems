/**
 * Problem:
 *   https://leetcode.com/problems/maximum-swap/description/
 * Solution:
 *   https://leetcode.com/problems/maximum-swap/submissions/1426769696/
 * Thought: the idea is swap the smallest most significant digit with
 *   the biggest most insignificnat digit
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */
#include <string>

class Solution_bf
{
public:
    int maximumSwap(int num)
    {
        std::string str = std::to_string(num);
        int max = -1, l_swap = -1, r_swap = -1;
        for (int i = 0; i < str.length() - 1; ++i)
        {
            int cur = str[i] - '0';
            for (int j = i + 1; j < str.length(); ++j)
            {
                int next = str[j] - '0';
                // next >= max since we want the right most digit to swap
                // 3737 -> 7733 instead of 7337
                if (next > cur && next >= max)
                {
                    max = next;
                    l_swap = i;
                    r_swap = j;
                }
            }
            // if found swap value, no need to iterate
            // since we already swapped more significant values
            if (r_swap != -1) break;
        }

        if (r_swap != -1) std::swap(str[l_swap], str[r_swap]);
        return std::stoi(str);
    }
};
