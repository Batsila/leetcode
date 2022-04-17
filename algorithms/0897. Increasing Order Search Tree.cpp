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
    vector<int> vals;
public:
    TreeNode* increasingBST(TreeNode* root) 
    {
        dfs(root);
        
        if (not vals.size())
        {
            return NULL;
        }
        
        TreeNode* new_root = new TreeNode(vals[0]);
        TreeNode* pr = new_root;
        
        for (int i = 1; i < vals.size(); ++i)
        {
            TreeNode* temp = new TreeNode(vals[i]);
            pr->right = temp;
            pr = temp;
        }
        
        return new_root;
    }
    
    void dfs(TreeNode* node)
    {
        if (node)
        {
            dfs(node->left);
            vals.push_back(node->val);
            dfs(node->right);
        }
    }
};