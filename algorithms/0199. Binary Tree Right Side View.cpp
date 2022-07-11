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
    bool du[100];
    vector<int> ans;
public:
    vector<int> rightSideView(TreeNode* root)
    {
        dfs(root, 0);
        
        return ans;
    }
    
    void dfs(TreeNode* node, int d)
    {
        if (node)
        {
            if (not du[d])
            {
                ans.push_back(node->val);
                du[d] = true;
            }
            
            dfs(node->right, d + 1);
            dfs(node->left, d + 1);
        }
    }
};