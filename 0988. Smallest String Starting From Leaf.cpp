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
    string smallestFromLeaf(TreeNode* root, string path = "")
    {
        if (root)
        {
            path = char('a' + root->val) + path;

            if (root->left and root->right)
            {
                string left_path = smallestFromLeaf(root->left, path);
                string right_path = smallestFromLeaf(root->right, path);

                return min(left_path, right_path);
            }
            else if (root->left)
            {
                return smallestFromLeaf(root->left, path);
            }
            else if (root->right)
            {
                return smallestFromLeaf(root->right, path);
            }
            else
            {
                return path;
            }
        }

        return "";
    }
};