/**
 * Problem:
 *   https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 * Solution:
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
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
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode* root) {}
};
