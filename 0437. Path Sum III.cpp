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
    int ts;
    int ans = 0;
    vector<int> path;
    int curr_sum = 0;
public:
    int pathSum(TreeNode* root, int targetSum)
    {
        ts = targetSum;
        
        dfs(root);
        
        return ans;
    }
    
    void dfs(TreeNode* node)
    {
        if (node)
        {
            curr_sum += node->val;
            path.push_back(node->val); 
            
            int s = curr_sum;
            
            for (int i = 0; i < path.size(); ++i)
            {
                if (i > 0)
                {
                    s -= path[i - 1];
                }
                
                if (s == ts)
                {
                    ++ans;
                }
            }
            
            dfs(node->left);
            dfs(node->right);
            
            curr_sum -= node->val;
            path.pop_back();
        }
    }
};