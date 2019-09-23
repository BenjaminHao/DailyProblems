# House Robber
### You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

### Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
---
### Example 1:

Input: [1,2,3,1]  
Output: 4
> Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).  
Total amount you can rob = 1 + 3 = 4.

### Example 2:

Input: [2,7,9,3,1]  
Output: 12
> Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).  
Total amount you can rob = 2 + 9 + 1 = 12.
---
## **Thinking**
I am a robber. I am at the `i`'th house. Am I going to rob it or not? Here are the factors:
- If robbing, then I can't rob the former house (`i - 1`), the maximum amount of money I can rob is **the maximum value of `i - 2` plus this house**.
- If not robbing, the maximum amount of money is **after robbing the `i - 1`'th house**, then I go to the next house.

So we can get:  
`rob(i) = max(rob(i - 2) + currentHouseValue, rob(i - 1))`  
> It is the key to solve this problem.