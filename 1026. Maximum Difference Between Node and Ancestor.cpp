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
    int maxAncestorDiff(
        TreeNode* root,
        int minimum = INT_MAX,
        int maximum = INT_MIN)
    {
        if (root)
        {
            minimum = min(minimum, root->val);
            maximum = max(maximum, root->val);
        
            int l = maxAncestorDiff(root->left, minimum, maximum);
            int r = maxAncestorDiff(root->right, minimum, maximum);
        
            return max(l, r);
        }
        
        return maximum - minimum;
    }
};