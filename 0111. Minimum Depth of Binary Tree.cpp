/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    int minDepth(TreeNode* root, int d = 0) 
    {
        if (root)
        {
            if (not root->left and not root->right)
            {
                return d + 1;
            }

            int ans = INT_MAX;

            if (root->left)
            {
                ans = min(ans, minDepth(root->left, d + 1));
            }

            if (root->right)
            {
                ans = min(ans, minDepth(root->right, d + 1));
            }

            return ans;
        }

        return 0;
    }
};