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
    map<TreeNode*, int> dp;
public:
    int rob(TreeNode* root)
    {
        if (not root)
        {
            return 0;
        }
        
        if (dp.find(root) != dp.end())
        {
            return dp[root];
        }
        
        int sum = root->val;
        
        if (root->left)
        {
            sum += rob(root->left->left) + rob(root->left->right);
        }
        
        if (root->right)
        {
            sum += rob(root->right->left) + rob(root->right->right);
        }
        
        sum = max(sum, rob(root->left) + rob(root->right));
        dp[root] = sum;
        
        return sum;
    }
};