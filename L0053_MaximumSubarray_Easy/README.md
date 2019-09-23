# Maximum Subarray
### Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

## Example:

- Input: [-2,1,-3,4,-1,2,1,-5,4],  
Output: 6
> Explanation: [4,-1,2,1] has the largest sum = 6.

## Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

---
## **Thinking**
If we are at the i'th element, how can we get the maximum subarray though the i'th element and former elements?  
Of course we want more positive numbers and less negative numbers. So if we have a subarray that might be the maximum subarray, we want the next element of it is a positive number. So the sum of the subarray would be bigger.  
Thinking that we have a positive element. The sum of the subarray before this element is a positive number. If add this element into the subarray, the subarray would be bigger. BUT if the sum of the subarray is negative. WTF, the element will lose its value. Then why doesn't the element become a new subarray?

OK, let's do this.  
We can define an array `dp[i]`, `dp[i]` is the maximum subarray that ending with the i'th element. Assuming that we already know `dp[0]` to `dp[i - 1]`. `dp[i - 1]` is the maximum subarray that the last element is `i - 1`. If `dp[i - 1]` is smaller than 0, then **`dp[i]` plus subarray with any length** will be **smaller** than **NOT plus**, i.e. the element itself is the maximum subarray.  
That is:
```
if (dp[i - 1] > 0)
{
    dp[i] = dp[i - 1] + nums[i];
}
else
{
    dp[i] = nums[i];
}
```