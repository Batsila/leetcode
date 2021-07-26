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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        if (nums.size() > 0)
        {
            int m = nums.size() / 2;
            
            TreeNode* node = new TreeNode(nums[m]);
            
            vector<int> lnums = vector<int>(nums.begin(), nums.begin() + m);
            vector<int> rnums = vector<int>(nums.begin() + m + 1, nums.end());
            
            node->left = sortedArrayToBST(lnums);
            node->right = sortedArrayToBST(rnums);
            
            return node;
        }
        
        return NULL;
    }
};