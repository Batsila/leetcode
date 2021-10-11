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
    int ans;
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        count(root);
        
        return ans;
    }
    
    int count(TreeNode* node)
    {
        if (node == NULL)
        {
            return 0;
        }
        
        int l = count(node->left);
        int r = count(node->right);
        ans = max(ans, l + r);
        
        return max(l, r) + 1;
    }
};