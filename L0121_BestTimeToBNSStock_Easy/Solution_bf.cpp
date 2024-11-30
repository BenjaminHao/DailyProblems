/**
 * Problem:
 *   https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 * Solution: Time Limit Exceeded
 *   https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1466845290/
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */
#include <vector>
using namespace std;

class Solution_bf
{
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; ++i)
        {
            int buy = prices[i];
            for (int j = i + 1; j < prices.size(); ++j)
            {
                int sell = prices[j];
                profit = max(profit, sell - buy);
            }
        }
        return profit;
    }
};
