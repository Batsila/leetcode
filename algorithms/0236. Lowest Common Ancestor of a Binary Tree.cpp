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
    TreeNode* ans;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        dfs(root, p, q);
        
        return ans;
    }
    
    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if (not node)
        {
            return false;
        }
        
        bool l = dfs(node->left, p, q);
        bool r = dfs(node->right, p, q);
        bool c  = node == p or node == q;
        
        if ((l and r) or (l and c) or (r and c))
        {
            ans = node;
        }
        
        return l or r or c;
    }
};