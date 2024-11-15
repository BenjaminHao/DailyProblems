/**
 * Problem:
 *   https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 * Solution:
 *   https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/1446263995/
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        postOrder(root);
        return res;
    }

private:
    void postOrder(TreeNode* root)
    {
        if (!root) return;
        postOrder(root->left);
        postOrder(root->right);
        res.push_back(root->val);
    }
};
