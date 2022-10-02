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
class BSTIterator
{
    stack<TreeNode*> p;
public:
    BSTIterator(TreeNode* root)
    {
        auto c = root;
        
        while (c)
        {
            p.push(c);
            c = c->left;
        }
    }
    
    int next()
    {
        auto res = p.top();
        p.pop();
        
        auto c = res->right;
        
        while (c)
        {
            p.push(c);
            c = c->left;
        }  
        
        return res->val;
    }
    
    bool hasNext()
    {
        return not p.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */