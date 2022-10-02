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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root)
        {
            if (key < root->val)
            {
                root->left = deleteNode(root->left, key);
            }
            else if (key > root->val)
            {
                root->right = deleteNode(root->right, key);
            }
            else
            {
                if (not root->left and not root->right)
                {
                    return NULL;
                }
                
                if (not root->left or not root->right)
                {
                    if (root->left)
                    {
                        return root->left;
                    }
                    else
                    {
                        return root->right;
                    }
                }
                
                TreeNode* c = root->right;
                
                while (c->left)
                {
                    c = c->left;
                }
                
                root->val = c->val;
                root->right = deleteNode(root->right, c->val);
            }
        }
        
        return root;
    }
};