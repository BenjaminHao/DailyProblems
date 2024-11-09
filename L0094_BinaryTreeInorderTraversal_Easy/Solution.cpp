/**
 * Problem:
 *   https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 * Solution:
 *   https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/1446262921/
 * Time complexity: O(n)
 * Space complexity: O(l) where l is the levels of the binary tree
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

class Solution
{
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root)
    {
        inOrder(root);
        return res;
    }

private:
    void inOrder(TreeNode* root)
    {
        if (!root) return;
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
};
