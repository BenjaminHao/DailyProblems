/**
 * Problem:
 *   https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 * Solution:
 *   https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1466852347/
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0, buy = prices[0];

        for (int price : prices)
        {
            if (price < buy)
                buy = price;
            else if (price - buy > profit)
                profit = price - buy;
        }

        return profit;
    }
};
