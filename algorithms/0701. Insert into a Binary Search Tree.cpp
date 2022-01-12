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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if (not root)
        {
            TreeNode* new_node = new TreeNode(val);
            
            return new_node;
        }
        
        help(root, val);
        
        return root;
    }
    
    void help(TreeNode* node, int val)
    {
        if (val < node->val)
        {
            if (node->left)
            {
               help(node->left, val); 
            }
            else
            {
                TreeNode* new_node = new TreeNode(val);
                node->left = new_node;
            }
        }
        else
        {
            if (node->right)
            {
                help(node->right, val);
            }
            else
            {
                TreeNode* new_node = new TreeNode(val);
                node->right = new_node;
            }
        }
    }
};