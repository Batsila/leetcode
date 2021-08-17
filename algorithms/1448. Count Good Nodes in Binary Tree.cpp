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
    int ans;
public:
    int goodNodes(TreeNode* root) 
    {
        dfs(root);
        
        return ans;
    }
    
    void dfs(TreeNode* node, int m = -111111)
    {
        if (node)
        {
            if (node->val >= m)
            {
                ++ans;
            }
            
            int nm = max(node->val, m);
            
            dfs(node->right, nm);
            dfs(node->left, nm);
        }
    }
};