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
    int i = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (i >= preorder.size())
        {
            return NULL;
        }
        
        int val = preorder[i++];
        auto node = new TreeNode(val);
        
        auto itr = find(inorder.begin(), inorder.end(), val);
        
        if (itr > inorder.begin())
        {
            auto l = vector<int>(inorder.begin(),  itr - 1);
            node->left = buildTree(preorder, l);
        }
        
        if (itr < inorder.end())
        {
            auto r = vector<int>(itr + 1,  inorder.end());
            node->right = buildTree(preorder, r);
        }
        
        return node;
    }
};