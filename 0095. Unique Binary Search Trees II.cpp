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
    vector<TreeNode*> generateTrees(int n)
    {
        return dfs(1, n);
    }
    
    vector<TreeNode*> dfs(int start, int end)
    {
        if (start > end)
        {
            return { NULL };
        }
        
        if (start == end)
        {
            return { new TreeNode(start) };
        }
        
        vector<TreeNode*> ans;
        
        for (int i = start; i <= end; ++i)
        {
            for (TreeNode* l : dfs(start, i - 1))
            {
                for (TreeNode* r : dfs(i + 1, end))
                {
                    ans.push_back(new TreeNode(i, l, r));
                }
            }
        }
        
        return ans;
    }
};