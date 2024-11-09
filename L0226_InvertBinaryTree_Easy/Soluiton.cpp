/**
 * Problem:
 *   https://leetcode.com/problems/invert-binary-tree/description/
 * Solution:
 *   https://leetcode.com/problems/invert-binary-tree/submissions/1446281472/
 * Thought: Invert pointers, not values.
 * Time complexity: O(n)
 * Space complexity: O(l) where l is the levels of the binary tree
 */
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

class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        invert(root);
        return root;
    }

private:
    void invert(TreeNode* node)
    {
        if (!node) return;
        swap(node->left, node->right);
        invert(node->left);
        invert(node->right);
    }
};
