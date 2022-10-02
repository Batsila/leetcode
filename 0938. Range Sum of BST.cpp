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
    int rangeSumBST(TreeNode* root, int l, int r) 
    {
        if (not root)
        {
            return 0;
        }
        
        int sum = rangeSumBST(root->left, l, r);
        sum += rangeSumBST(root->right, l, r);
        
        if (root->val <= r and root->val >= l)
        {
            sum += root->val;
        }
            
        return sum;
    }
};