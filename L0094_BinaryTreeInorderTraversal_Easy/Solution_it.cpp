/**
 * Problem:
 *   https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 * Solution:
 *
 * Time complexity: O(n)
 * Space complexity: O(h) where h is the height of the binary tree
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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stack;
        if (!root) stack.push(root);

        while (!stack.empty())
        {
        }
    }
};
