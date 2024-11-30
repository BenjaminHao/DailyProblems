/**
 * Problem:
 *   https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 * Solution:
 *   https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1466851037/
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int max_profit = 0, min_price = prices[0];

        for (int price : prices)
        {
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }

        return max_profit;
    }
};
