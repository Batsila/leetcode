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
    int result = 0;
public:
    int distributeCoins(TreeNode* root)
    {
        dfs(root);

        return result;
    }

    int dfs(TreeNode* node)
    {
        if (node)
        {
            int left = dfs(node->left);
            int right = dfs(node->right);
            int moves = abs(left) + abs(right);
            result += moves;

            return node->val + left + right - 1;
        }

        return 0;
    }
};