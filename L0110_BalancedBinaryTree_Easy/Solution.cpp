/**
 * Problem:
 *   https://leetcode.com/problems/balanced-binary-tree/description/
 * Solution:
 *   https://leetcode.com/problems/balanced-binary-tree/submissions/1450923158/
 * Time complexity: O(n)
 * Space complexity: O(n)
 **/
// Definition for a binary tree node.
#include <algorithm>
#include <cstdlib>
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
    bool isBalanced(TreeNode* root)
    {
        if (getHeight(root) == -1) return false;
        return true;
    }

private:
    int getHeight(TreeNode* node)
    {
        if (!node) return 0;
        int leftHight = getHeight(node->left);
        int rightHight = getHeight(node->right);
        if (leftHight == -1 || rightHight == -1 ||
            abs(rightHight - leftHight) > 1)
            return -1;
        return max(leftHight, rightHight) + 1;
    }
};
