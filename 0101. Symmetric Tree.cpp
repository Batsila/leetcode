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
    bool isSymmetric(TreeNode* root) 
    {
        if (root)
        {
            return isSymmetric(root->left, root->right);
        }

        return false;
    }
    
    bool isSymmetric(TreeNode* l, TreeNode* r)
    {
        if (not l and not r)
        {
           return true; 
        }
        
        if (l and r and l->val == r->val)
        {
            return isSymmetric(l->right, r->left) and isSymmetric(l->left, r->right);
        }
        
        return false;
    }
};