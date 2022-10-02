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
    vector<int> t;
public:
    bool isValidBST(TreeNode* root) 
    {
        return isValidBST(root, -2147483649, 2147483649);
    }
    
    bool isValidBST(TreeNode* node, long long l, long long r)
    {
        if (!node)
        {
            return true;
        }
        
        if (node->val <= l || node->val >= r)
        {
            return false;
        }
        
        return isValidBST(node->left, l, node->val) && isValidBST(node->right, node->val, r);
    }
};