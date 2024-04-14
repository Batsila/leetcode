/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode* root, bool is_left = false)
    {
        if (root)
        {
            if (is_left and not root->left and not root->right)
            {
                return root->val;
            }

            return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
        }

        return 0;
    }
};