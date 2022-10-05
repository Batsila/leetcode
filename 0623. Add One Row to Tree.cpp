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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if (depth == 1)
        {
            auto ans = new TreeNode(val);
            ans->left = root;
            
            return ans;
        }
        
        dfs(root, val, depth, 1);
        
        return root;
    }
    
    void dfs(TreeNode* node, int val, int depth, int pd)
    {
        if (node)
        {
            if (pd + 1 == depth)
            {
                auto t = node->left;
                node->left = new TreeNode(val);
                node->left->left = t;
                t = node->right;
                node->right = new TreeNode(val);
                node->right->right = t;
            }
            else
            {
                dfs(node->left, val, depth, pd + 1);
                dfs(node->right, val, depth, pd + 1);
            }
        }
    }
};