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
class Solution {
    vector<int> ans;
    bool imp;
    int i;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) 
    {
        dfs(root, voyage);
        
        if (imp)
        {
            ans.clear();
            ans.push_back(-1);
        }
        
        return ans;
    }
    
    void dfs(TreeNode* node, vector<int>& v)
    {
        if (!node)
        {
            return;
        } 
        
        if (i >= v.size() || node->val != v[i])
        {
            imp = true;
            return;
        }
        
        ++i;
        
        if (node->left && i < v.size() && node->left->val != v[i])
        {
            ans.push_back(node->val);
            
            auto temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
        
        dfs(node->left, v);
        dfs(node->right, v);
    }
    
    
};