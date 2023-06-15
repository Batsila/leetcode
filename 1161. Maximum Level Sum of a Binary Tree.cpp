/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
    int sum[1004];
    int h = 0;
public:
    int maxLevelSum(TreeNode* root) 
    {
        dfs(root, 0);
        
        int max_sum = INT_MIN;
        int ans;
        
        for (int i = 0; i <= h; ++i)
        {
            if (sum[i] > max_sum)
            {
                max_sum = sum[i];
                ans = i + 1;
            }
        }
        
        return ans;
    }
    
    void dfs(TreeNode* node, int d)
    {
        if (node)
        {
            h = max(h, d);
            sum[d] += node->val;
            dfs(node->left, d + 1);
            dfs(node->right, d + 1);
        }
    }
};