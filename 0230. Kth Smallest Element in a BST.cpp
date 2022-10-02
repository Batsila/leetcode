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
    int k;
    int ans;
public:
    int kthSmallest(TreeNode* root, int k)
    {
        this->k = k;
        
        dfs(root);
        
        return ans;
    }
    
    void dfs(TreeNode* node)
    {
        if (node and k > 0)
        {
            dfs(node->left);
            --k;
            
            if (not k)
            {
                ans = node->val;
            }
            
            dfs(node->right);
        }
    }
};