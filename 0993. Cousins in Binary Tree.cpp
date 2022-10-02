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
    int xp;
    int yp;
    int xd;
    int yd;
    int x;
    int y;
    
public:
    bool isCousins(TreeNode* root, int x, int y)
    {
        this->x = x;
        this->y = y;
        
        dfs(root, 0, 0);
        
        return xp != 0 and yp != 0 and xp != yp and xd == yd;
    }
    
    void dfs(TreeNode* node, int p, int d)
    {
        if (node)
        {
            if (node->val == x)
            {
                xp = p;
                xd = d;
            }
            
            if (node->val == y)
            {
                yp = p;
                yd = d;
            }
            
            dfs(node->left, node->val, d + 1);
            dfs(node->right, node->val, d + 1);
        }
    }
};