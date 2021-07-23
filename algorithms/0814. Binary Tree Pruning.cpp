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
    TreeNode* pruneTree(TreeNode* root)
    {
        if (help(root))
        {
            return root;
        }
        
        return NULL;
    }
    
    bool help(TreeNode* node)
    {
        if (node)
        {
            bool is_r = help(node->right);
            bool is_l = help(node->left);
            
            if (not is_r)
            {
                node->right = NULL;
            }
            
            if (not is_l)
            {
                node->left = NULL;
            }
            
            return is_r or is_l or node->val;
        }
        
        return false;
    }
};