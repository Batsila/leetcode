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
    int maxd = 0;
    int sum = 0;
public:
    int deepestLeavesSum(TreeNode* root) 
    {
        dfs(root, 0);
        
        return sum;
    }
    
    void dfs(TreeNode* node, int d)
    {
        if (!node->left && !node->right)
        {
            if (d == maxd)
            {
                sum += node->val;
            }
            else if (d > maxd)
            {
                maxd = d;
                sum = node->val;
            }
        }
        if (node->left)
        {
            dfs(node->left, d + 1);
        }
        if (node->right)
        {
            dfs(node->right, d + 1);
        }
    }
};