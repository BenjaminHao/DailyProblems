/**
 * Problem:
 *   https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 * Solution:
 *   https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/1452944586/
 * Time complexity: O(n)
 * Space complexity: O(h) where h is the hight of the binary tree
 */
#include <stack>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stack;
        if (root) stack.push(root);

        while (!stack.empty())
        {
            TreeNode* node = stack.top();
            stack.pop();
            res.push_back(node->val);
            if (node->right) stack.push(node->right);  // right first, last out
            if (node->left) stack.push(node->left);
        }

        return res;
    }
};
