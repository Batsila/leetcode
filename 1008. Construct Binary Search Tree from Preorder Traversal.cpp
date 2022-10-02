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
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        return help(preorder);
    }
    
    TreeNode* help(vector<int> a)
    {
        if (!a.size())
        {
            return NULL;
        }
        
        TreeNode* node = new TreeNode(a[0]);
        
        a.erase(a.begin());
        
        vector<vector<int>> t = sub(a, node->val);
        
        node->left = help(t[0]);
        node->right = help(t[1]);
        
        return node;
    }
    
    vector<vector<int>> sub(vector<int>& a, int val)
    {
        vector<vector<int>> t;
        vector<int> min_t;
        vector<int> max_t;
        
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] < val)
                min_t.push_back(a[i]);
            else
                max_t.push_back(a[i]);
        }
        
        t.push_back(min_t);
        t.push_back(max_t);
        
        return t;
    }
};