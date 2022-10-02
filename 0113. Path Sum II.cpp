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
    int n[100000];
    vector<vector<int>> paths;
    int s;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        s = sum;
        vector<int> path;
        dfs(root, path, 0);
        
        return paths;
    }
    
    void dfs(TreeNode* node, vector<int> path, int curr_sum)
    {
        if (node)
        {
            int value = node->val;
            curr_sum += value;
            path.push_back(value); 
            
            if (!node->left && !node->right)
            {
                if (curr_sum == s)
                {
                    paths.push_back(vector<int>(path));
                }
            }
            
            dfs(node->left, path, curr_sum);
            dfs(node->right, path, curr_sum);
            
            curr_sum -= value;
            path.pop_back();
        }
    }
};