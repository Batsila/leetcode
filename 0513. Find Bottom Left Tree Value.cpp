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
    int depth = -1;
    int ans = 0;
public:
    int findBottomLeftValue(TreeNode* root)
    {
        dfs(root);

        return ans;
    }

    void dfs(TreeNode* node, int d = 0)
    {
        if (node)
        {
            if (d > depth)
            {
                depth = d;
                ans = node->val;
            }

            dfs(node->left, d + 1);
            dfs(node->right, d + 1);
        }
    }
};