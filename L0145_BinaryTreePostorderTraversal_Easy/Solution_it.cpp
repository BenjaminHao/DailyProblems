/**
 * Problem:
 *   https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 * Solution:
 *   https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/1452949018/
 * Time complexity: O(n)
 * Space complexity: O(h) where h is the hight of the binary tree
 */
#include <algorithm>
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
class Solution_re
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stack;
        if (root) stack.push(root);

        while (!stack.empty())
        {
            TreeNode* node = stack.top();
            stack.pop();
            res.push_back(node->val);                  // mid
            if (node->left) stack.push(node->left);    // left, last out
            if (node->right) stack.push(node->right);  // right
        }  // after this, mid->right->left
        reverse(res.begin(), res.end());  // left->right->mid
        return res;
    }
};
