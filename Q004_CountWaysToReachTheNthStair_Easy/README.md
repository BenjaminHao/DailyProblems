# Count ways to reach the n’th stair
### There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.

![stairs](https://media.geeksforgeeks.org/wp-content/uploads/nth-stair.png "Count ways to reach the n'th stair")

**This is a classic dynamic programming problem.**

## Examples: 
* Input: n = 1  
Output: 1
> There is only one way to climb 1 stair
---
* Input: n = 2  
Output: 2
> There are two ways: (1, 1) and (2)
---
* Input: n = 3  
Output: 3
> There are there ways: (1, 1, 1), (2, 1), and (1, 2)
---
* Input: n = 4  
Output: 5
> (1, 1, 1, 1), (1, 1, 2), (2, 1, 1), (1, 2, 1), (2, 2)
---

## Thinking:
If function F(n) is persenting the number of ways, considering we have 10 stairs, there are 2 situations here:
1. we reach the 10th stair from the 9th stair by climbing 1 stair
2. we reach the 10th stair from the 8th stair by climbing 2 stairs

Actucally, **for any n'th stair**, we will have these 2 situations, i.e. **climbing 1 stair from n-1's stair** or **climbing 2 stairs from n-2's stair**

We will find that **F(10) = F(9) + f(8)**, i.e. the ways to reach the 10th stair equals to the ways to reach the 9th stair plus the ways to reach the 8th stair. Futhermore, we can get F(9) = F(8) + F(7), F(8) = F(7) + F(6), etc.

That is, **F(N) = F(N - 1) + F(N - 2)**, and F(1) = 1, F(2) = 2.

So we can use recursion to solve this problem:
### **Recursion**
```cpp
int climbStairs(int n)
{
    if (n < 1) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climbStairs(n - 1) + climbStairs(n - 2);
}
```

**BUT**, there's a problem here: the time complexity is very high
![Time Complexity](https://upload.wikimedia.org/wikipedia/commons/5/5f/FibbonacciRecurisive.png)

In order to solve F(N), we will caculate function 2^N times, i.e. the time complexity is O(2^N). There are tons of repeated caculations.

How to solve this problem?  
In recursion, we caculate from top to bottom. What if we caculate from bottom to top?  
We already know F(1) = 1, F(2) = 2, so F(3) = F(2) + F(1) = 3, in addition, F(4) = F(3) + F(2) = 5, etc.

So, we can create an array and save these numbers. The time complexity is O(N).

### **Dynamic Programming**
```cpp
int climbStairs(int n)
{
    if (n == 1) return 1;
    int* step = new int[n + 1];
    step[1] = 1;
    step[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        step[i] = step[i - 1] + step[i - 2];
    }

    return step[n];
}
```

> see Leetcode #70.