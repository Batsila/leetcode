/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        dfs(root, 0);
        
        return ans;
    }

    void dfs(TreeNode* node, int d)
    {
        if (node)
        {
            if (ans.size() <= d)
            {
                ans.push_back(vector<int>());
            }
            
            ans[d].push_back(node->val);
        
            dfs(node->left, d + 1);
            dfs(node->right, d + 1);
        }
    }
};