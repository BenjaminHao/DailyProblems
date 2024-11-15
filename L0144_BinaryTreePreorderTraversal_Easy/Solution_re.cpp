/**
 * Problem:
 *   https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 * Solution:
 *   https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/1446260950/
 * Time complexity: O(n)
 * Space complexity: O(h) where h is the hight of the binary tree
 */
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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root)
    {
        preOrder(root);
        return res;
    }

private:
    void preOrder(TreeNode* root)
    {
        if (!root) return;
        res.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
};
