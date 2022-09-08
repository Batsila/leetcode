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
    vector<int> inorderTraversal(TreeNode* root)
    {
        if (root)
        {
            auto l = inorderTraversal(root->left);
            l.push_back(root->val);
            auto r = inorderTraversal(root->right);
            l.insert(l.end(), r.begin(), r.end());
            
            return l;
        }
        
        return {};
    }
};