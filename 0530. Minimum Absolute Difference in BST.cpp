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
    vector<int> vals;
public:
    int getMinimumDifference(TreeNode* root)
    {
        dfs(root);

        int ans = INT_MAX;

        for (int i = 1; i < vals.size(); ++i)
        {
            ans = min(ans, vals[i] - vals[i - 1]);
        }

        return ans;
    }

    void dfs(TreeNode* node)
    {
        if (node)
        {
            dfs(node->left);
            vals.push_back(node->val);
            dfs(node->right);
        }
    }
};