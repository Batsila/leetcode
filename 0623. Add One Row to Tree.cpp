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
        
        dfs(root, val, depth);
        
        return root;
    }
    
    void dfs(TreeNode* node, int val, int traget_depth, int current_depth = 1)
    {
        if (node)
        {
            ++current_depth;

            if (current_depth == traget_depth)
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
                dfs(node->left, val, traget_depth, current_depth);
                dfs(node->right, val, traget_depth, current_depth);
            }
        }
    }
};