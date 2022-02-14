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
    int maxDepth(TreeNode* root, int d = 0) 
    {
        if (not root)
        {
            return d;
        }
        
        ++d;
        
        return max(maxDepth(root->left, d), maxDepth(root->right, d));
    }
};