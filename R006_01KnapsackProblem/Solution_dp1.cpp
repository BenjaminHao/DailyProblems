/**
 * ┌────────┬────────┬────────┐ ┌──────────┬───┬────┬────┬────┬────┬────┐
 * │        │ Weight │ Profit │ │ dp[i][j] │ 0 │  1 │ 2  │ 3  │ 4  │ 5  │
 * ├────────┼────────┼────────┤ ├──────────┼───┼────┼────┼────┼────┼────┤
 * │ item 0 │    1   │   15   │ │     0    │ 0 │ 15 │ 15 │ 15 │ 15 │ 15 │
 * ├────────┼────────┼────────┤ ├──────────┼───┼────┼────┼────┼────┼────┤
 * │ item 1 │    3   │   20   │ │     1    │ 0 │ 15 │ 15 │ 20 │ 35 │ 35 │
 * ├────────┼────────┼────────┤ ├──────────┼───┼────┼────┼────┼────┼────┤
 * │ item 2 │    4   │   40   │ │     2    │ 0 │ 15 │ 15 │ 20 │ 40 │ 55 │
 * └────────┴────────┴────────┘ └──────────┴───┴────┴────┴────┴────┴────┘
 * dp[i][j] - max profit of putting item i into a knapsack with capacity of j
 * dp[i-1][j] - exclude item i, dp[i-1][j-weight[i]]+profit[i] - inclue item i
 * dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + profit[i])
 * Question:
 * Can we swap these 2 for-loops? Why no need iterate backwards?
 */
#include <algorithm>
#include <vector>

class Solution_dp1
{
    int maxValue(int items, int capacity, std::vector<int> profit,
                 std::vector<int> weight)
    {
        std::vector<std::vector<int>> dp(items + 1,
                                         std::vector<int>(capacity + 1));
        // capacity is 0, profit = 0
        for (int i = 0; i <= items; ++i)
        {
            dp[i][0] = 0;
        }
        // put item0 into knapsack
        for (int j = 1; j <= capacity; ++j)
        {
            if (weight[0] <= capacity)
                dp[0][j] = profit[0];
            else
                dp[0][j] = 0;
        }

        for (int y = 0; y <= items; ++y)
        {
            for (int x = 0; x <= capacity; ++x)
            {
                dp[y][x] = std::max(dp[y - 1][x],
                                    dp[y - 1][x - weight[y]] + profit[y]);
            }
        }

        return dp[items][capacity];
    }
};
