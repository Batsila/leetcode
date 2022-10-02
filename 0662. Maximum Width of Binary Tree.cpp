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
    int widthOfBinaryTree(TreeNode* root)
    {
        if (not root)
        {
            return 0;
        }
        
        int ans = 1;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (not q.empty())
        {
            queue<pair<TreeNode*, int>> cq = q;
            q = queue<pair<TreeNode*, int>>();
            
            int start = cq.front().second;
            int end = cq.back().second;
            
            ans = max(ans, end - start + 1);
            
            while (not cq.empty())
            {
                auto c = cq.front();
                cq.pop();
                
                if (c.first->left)
                {
                    q.push({c.first->left, (long)2 * (c.second - start) + 1});
                }
                
                if (c.first->right)
                {
                    q.push({c.first->right, (long)2 * (c.second - start) + 2});
                }
            }
        }
        
        return ans;
    }
};