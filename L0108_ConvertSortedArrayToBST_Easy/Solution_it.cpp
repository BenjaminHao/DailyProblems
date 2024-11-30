/**
 * Problem:
 *   https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 * Solution:
 *  https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/1466131807/
 * Time complexity: O(n)
 * Space complexity: O(n)
 **/
// Definition for a binary tree node.
#include <stack>
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

class Solution_it
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        stack<TreeNode*> stack;
        // TODO: finish this
    }
};
