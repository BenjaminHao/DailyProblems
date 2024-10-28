/**
 * Problem:
 *   https://leetcode.com/problems/house-robber-iii/description/
 * Solution:
 *
 * Time complexity:
 * Space complexity:
 *
 */
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
    int rob(TreeNode* root)
    {
        // TODO: solve house robber iii
        return 0;
    }
};
