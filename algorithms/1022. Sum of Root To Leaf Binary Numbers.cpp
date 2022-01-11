/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
    int sum;
public:
    int sumRootToLeaf(TreeNode* root) 
    {
        dfs(root, { });
        
        return sum;
    }
    
    void dfs(TreeNode* node, vector<int> v)
    {
        if (node)
        {
            vector<int> t(v);
            t.push_back(node->val);
            
            if (not node->left and not node->right)
            {
                reverse(t.begin(), t.end());
                
                for (int i = 0; i < t.size(); ++i)
                {
                    if (t[i])
                    {
                        sum += pow(2, i);
                    }
                }
            }
            else
            {
                dfs(node->left, t);
                dfs(node->right, t);
            }
        }
    }
};