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
    int sum;
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        dfs(root, false);
        
        return sum;
    }
    
    void dfs(TreeNode* node, bool l)
    {
        if (node)
        {
            if (not node->left and not node->right and l)
            {
                sum += node->val;
            }
            else
            {
                dfs(node->left, true);
                dfs(node->right, false);
            }
        }
    }
};