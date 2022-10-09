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
    vector<int> nums;
public:
    bool findTarget(TreeNode* root, int k)
    {
        dfs(root);
        int l = 0;
        int r = nums.size() - 1;
        
        while (r > l)
        {
            if (nums[l] + nums[r] == k)
            {
                return true;
            }
            else if (nums[l] + nums[r] > k)
            {
                --r;
            }
            else
            {
                ++l;
            }
        }
        
        return false;
    }
    
    void dfs(TreeNode* node)
    {
        if (node)
        {
            dfs(node->left);
            nums.push_back(node->val);
            dfs(node->right);
        }
    }
};