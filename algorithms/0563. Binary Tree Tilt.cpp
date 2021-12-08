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
public:
    int findTilt(TreeNode* root)
    {   
        help(root);
        
        return ans;
    }
    
    int help(TreeNode* node)
    {
        if (not node)
        {
            return 0;
        }
        
        int lsum = help(node->left);
        int rsum = help(node->right);
        int sum = node->val + lsum + rsum;
        
        ans += abs(lsum - rsum);
        
        return sum;
    }
};