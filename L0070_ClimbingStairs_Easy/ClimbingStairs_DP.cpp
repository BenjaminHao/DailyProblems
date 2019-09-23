/** Leetcode 70: https://leetcode.com/problems/climbing-stairs/
 *  Also See Q4. README.md
 *  Runtime: 4 ms, faster than 51.86% of C++ online submissions for Climbing Stairs.
 *  Memory Usage: 8.6 MB, less than 14.71% of C++ online submissions for Climbing Stairs.
**/

class Solution 
{
public:
    int climbStairs(int n) 
    {
        if (n == 1) return 1;
        int* step = new int[n + 1];
        step[1] = 1;
        step[2] = 2;
        
        for (int i = 3; i <= n; ++i)
        {
            step[i] = step[i - 2] + step[i - 1];
        }
        
        return step[n];
    }
};