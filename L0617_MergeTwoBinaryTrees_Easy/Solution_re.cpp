/**
 * Problem:
 *   https://leetcode.com/problems/merge-two-binary-trees/description/
 * Solution:
 *   https://leetcode.com/problems/merge-two-binary-trees/submissions/1452194935/
 * Time complexity: O(m+n)
 * Space complexity: O(m+n)
 */

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

class Solution
{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        if (!root1) return root2;
        if (!root2) return root1;

        TreeNode* newTree = new TreeNode();
        newTree->val = root1->val + root2->val;
        newTree->left = mergeTrees(root1->left, root2->left);
        newTree->right = mergeTrees(root1->right, root2->right);

        return newTree;
    }
};
