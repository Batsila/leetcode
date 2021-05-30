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
    int ans;
    set<TreeNode*> s;
public:
    int minCameraCover(TreeNode* root) 
    {
        s.insert(NULL);
        
        dfs(root, NULL);
        
        return ans;
    }
    
    void dfs(TreeNode* node, TreeNode* p)
    {
        if (node)
        {
            dfs(node->left, node);
            dfs(node->right, node);
            
            if (!p and s.find(node) == s.end()
               or s.find(node->left) == s.end()
               or s.find(node->right) == s.end())
            {
                ++ans;
                s.insert(node);
                s.insert(node->left);
                s.insert(node->right);
                s.insert(p);
            }
        }
    }
};