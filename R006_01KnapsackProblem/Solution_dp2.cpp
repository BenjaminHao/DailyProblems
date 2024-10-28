/**
 * ┌────────┬────────┬────────┐ ┌───────┬───┬────┬────┬────┬────┬────┐
 * │        │ Weight │ Profit │ │ dp[j] │ 0 │  1 │ 2  │ 3  │ 4  │ 5  │
 * ├────────┼────────┼────────┤ ├───────┼───┼────┼────┼────┼────┼────┤
 * │ item 0 │    1   │   15   │ │   0   │ 0 │ 15 │ 15 │ 15 │ 15 │ 15 │ ←
 * ├────────┼────────┼────────┤ ├───────┼───┼────┼────┼────┼────┼────┤ ↑override
 * │ item 1 │    3   │   20   │ │   1   │ 0 │ 15 │ 15 │ 20 │ 35 │ 35 │ ←
 * ├────────┼────────┼────────┤ ├───────┼───┼────┼────┼────┼────┼────┤ ↑override
 * │ item 2 │    4   │   40   │ │   2   │ 0 │ 15 │ 15 │ 20 │ 40 │ 55 │ ←
 * └────────┴────────┴────────┘ └───────┴───┴────┴────┴────┴────┴────┘
 * dp[j] - max profit of a knapsack with capacity of j
 * dp[j] = max(dp[j], dp[j - weight[i]] + profit[i])
 * Question:
 * why iterate backwards? Can we swap these 2 for-loops?
 */
#include <algorithm>
#include <vector>

class Solution_dp1
{
    int maxValue(int items, int capacity, std::vector<int> profit,
                 std::vector<int> weight)
    {
        std::vector<int> dp(capacity + 1, 0);

        for (int i = 0; i <= items; ++i)
        {
            // have to iterate backwards to prevent duplicates
            for (int j = capacity; j >= weight[i]; j--)
            {
                dp[j] = std::max(dp[j], dp[j - weight[i]] + profit[i]);
            }
        }

        return dp[capacity];
    }
};
