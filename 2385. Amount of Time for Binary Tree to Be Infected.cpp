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
    int amountOfTime(TreeNode* root, int start)
    {
        dfs(root, start);

        return ans;
    }

    int dfs(TreeNode* node, int start)
    {
        if (node)
        {
            int ld = dfs(node->left, start);
            int rd = dfs(node->right, start);

            if (node->val == start)
            {
                ans = max(ans, ld);
                ans = max(ans, rd);

                return -1;
            }
            else if (ld >= 0 and rd >= 0)
            {
                return max(ld, rd) + 1;
            }
            else
            {
                ans = max(ans, abs(ld) + abs(rd));

                return min(ld, rd) - 1;
            }
        }

        return 0;
    }
};