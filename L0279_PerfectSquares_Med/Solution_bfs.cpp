/**
 * Problem:
 *   https://leetcode.com/problems/perfect-squares/description/
 * Solution:
 *   TODO: solve this with bfs
 * Time complexity:
 * Space complexity:
 */
#include <cmath>
#include <unordered_set>
#include <vector>
class Solution
{
public:
    int numSquares(int n)
    {
        std::vector<int> sqr;
        // if n = 100, vector includes 0, 1, 4, 9, 16 ... 100
        for (int i = 0; i <= static_cast<int>(std::sqrt(n)); ++i)
            sqr.push_back(i * i);

        // todo
        return 0;
    }
};
