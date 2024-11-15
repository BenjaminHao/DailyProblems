/**
 * Problem:
 *   https://leetcode.com/problems/merge-sorted-array/description/
 * Solution:
 *
 * Time complexity: O((m+n)log(m+n))
 * Space complexity: O(1)
 */
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = 0;
        while (i < n) nums1[m++] = nums2[i++];
        sort(nums1.begin(), nums1.end());
    }
};
