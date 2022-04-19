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
    TreeNode* a = NULL;
    TreeNode* b = NULL;
    TreeNode* p = NULL;
public:
    void recoverTree(TreeNode* root)
    {
        inorder(root);
        
        swap(a->val, b->val);
    }
    
    void inorder(TreeNode* node)
    {
        if (node)
        {
            inorder(node->left);
            
            if (p and node->val < p->val)
            {
                if (a)
                {
                    b = node;
                    
                    return;
                }
                else
                {
                    a = p;
                    b = node;
                }
            }
            
            p = node;
            inorder(node->right);
        }
    }
};