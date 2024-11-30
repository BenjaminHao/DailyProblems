/**
 * Problem:
 *   https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 * Solution:
 *  https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/1466131807/
 * Time complexity: O(n)
 * Space complexity: O(n)
 **/
// Definition for a binary tree node.
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right)
    {
    }
};

class Solution_re
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, left, mid - 1);
        node->right = sortedArrayToBST(nums, mid + 1, right);
        return node;
    }
};
