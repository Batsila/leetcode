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
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> l1 = getLeafs(root1);
        vector<int> l2 = getLeafs(root2);
        
        return l1 == l2;
    }
    
    vector<int> getLeafs(TreeNode* root)
    {
        vector<int> leafs;
        dfs(root, leafs);
        
        return leafs;
    }
    
    void dfs(TreeNode* node, vector<int>& leafs)
    {
        if (node)
        {
            if (node->left or node->right)
            {
                dfs(node->left, leafs);
                dfs(node->right, leafs);
            }
            else
            {
                leafs.push_back(node->val);
            }
        } 
    }
};