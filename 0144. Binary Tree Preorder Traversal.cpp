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
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        dfs(root);

        return res;
    }

    void dfs(TreeNode* node)
    {
        if (node)
        {
            res.push_back(node->val);
            dfs(node->left);
            dfs(node->right);
        }
    }
};