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
    int ans = 0;
public:
    int longestZigZag(TreeNode* root)
    {
        if (root)
        {
            dfs(root->left, true, 1);
            dfs(root->right, false, 1);
        }

        return ans;
    }

    void dfs(TreeNode* node, bool isLeft, int l)
    {
        if (node)
        {
            ans = max(ans, l);

            if (isLeft)
            {
                dfs(node->right, false, l + 1);
                dfs(node->left, true, 1);
            }
            else
            {
                dfs(node->left, true, l + 1);
                dfs(node->right, false, 1);
            }
        }
    }
};