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
    vector<vector<int>> ans;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        dfs(root);

        for (int i = 1; i < ans.size(); i += 2)
        {
            reverse(ans[i].begin(), ans[i].end());
        }

        return ans;
    }

    void dfs(TreeNode* node, int d = 0)
    {
        if (node)
        {
            if (d >= ans.size())
            {
                ans.push_back(vector<int>());
            }
            
            ans[d].push_back(node->val);

            dfs(node->left, d + 1);
            dfs(node->right, d + 1);
        }
    }
};