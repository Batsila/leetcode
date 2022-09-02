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
private:
    int count[12345];
    double sum[12345];
    
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {   
        dfs(root, 0);
        
        vector<double> ans;
        
        for (int i = 0; count[i]; ++i)
        {
            ans.push_back(sum[i] / count[i]);
        }
        
        return ans;
    }
    
    void dfs(TreeNode* node, int d)
    {
        if (node)
        {
            ++count[d];
            sum[d] += node->val;
            dfs(node->left, d + 1);
            dfs(node->right, d + 1);
        }
        
    }
};