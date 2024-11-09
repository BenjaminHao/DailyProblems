/**
 * Problem:
 *   https://leetcode.com/problems/same-tree/description/
 * Solution:
 *   https://leetcode.com/problems/same-tree/submissions/1447082136/
 * Time complexity: O(min(n, m))
 * Space complexity: O(min(h1, h2)) where h is the hight of the binary tree
 **/
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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!p && !q) return true;
        if (p && q && p->val == q->val)
            return isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        return false;
    }
};
