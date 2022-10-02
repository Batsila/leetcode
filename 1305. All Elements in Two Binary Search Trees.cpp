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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> ans;
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        while (root1 or root2 or not s1.empty() or not s2.empty())
        {
            while (root1)
            {
                s1.push(root1);
                root1 = root1->left;
            }
            
            while (root2)
            {
                s2.push(root2);
                root2 = root2->left;
            }
            
            if (s2.empty() or not s1.empty() and s1.top()->val < s2.top()->val)
            {
                root1 = s1.top();
                s1.pop();
                
                ans.push_back(root1->val);
                root1 = root1->right;
            }
            else
            {
                root2 = s2.top();
                s2.pop();
                
                ans.push_back(root2->val);
                root2 = root2->right;
            }
        }
        
        return ans;
    }
};