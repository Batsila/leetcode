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
    bool evaluateTree(TreeNode* root)
    {
        if (root)
        {
            if (not root->left and not root->right)
            {
                return root->val == 1;
            }
            else 
            {
                bool left_val = evaluateTree(root->left);

                if ((root->val == 2 and left_val == true)
                    or (root->val == 3 and left_val == false))
                {
                    return left_val;
                }
                else
                {
                    return evaluateTree(root->right);
                }
            }
        }

        return false;
    }
};