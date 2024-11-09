/**
 * Problem:
 *   https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 * Solution:
 *   https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/1447107883/
 * Thought: BFS
 * Time complexity: O(n)
 * Space complexity: O(n)
 **/
#include <queue>
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

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (root) que.push(root);

        while (!que.empty())
        {
            int size = que.size();
            vector<int> nodes;
            while (size--)
            {
                TreeNode* node = que.front();
                que.pop();
                nodes.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(nodes);
        }

        return res;
    }
};
