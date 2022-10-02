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
    long fs;
    long ans = 0;
public:
    int maxProduct(TreeNode* root)
    {
        fs = get_sum(root);
        dfs(root);
        
        return ans % 1000000007;
    }
    
    void dfs(TreeNode* node)
    {
        if (node)
        {
            if (node->left)
            {
                long ls = node->left->val;
                ans = max(ans, ls * (fs - ls));
            }
            
            if (node->right)
            {
                long rs = node->right->val;
                ans = max(ans, rs * (fs - rs));
            }
            
            dfs(node->left);
            dfs(node->right);
        }
    }
    
    int get_sum(TreeNode* node)
    {
        if (not node)
        {
            return 0;
        }
        
        int sl = get_sum(node->left);
        int sr = get_sum(node->right);
        
        node->val += sl + sr;
        
        return node->val;
    }
};