/**
 * Problem:
 *   https://leetcode.com/problems/merge-sorted-array/description/
 * Solution:
 *   https://leetcode.com/problems/merge-sorted-array/submissions/1451999113/
 * Time complexity: O(m+n)
 * Space complexity: O(1)
 */
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int n1Pos = m - 1, n2Pos = n - 1, curPos = m + n - 1;
        while (n1Pos >= 0 && n2Pos >= 0)
        {
            if (nums1[n1Pos] < nums2[n2Pos])
            {
                nums1[curPos] = nums2[n2Pos];
                n2Pos--;
            }
            else
            {
                nums1[curPos] = nums1[n1Pos];
                n1Pos--;
            }
            curPos--;
        }
        // ↓ Unnecessary, if n1Pos>=0, those elements are already in correct pos
        // while (n1Pos >= 0) nums1[curPos--] = nums1[n1Pos--];
        while (n2Pos >= 0) nums1[curPos--] = nums2[n2Pos--];
    }
};
