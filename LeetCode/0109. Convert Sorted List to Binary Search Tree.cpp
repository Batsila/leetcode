/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* h) 
    {
        if (!h)
        {
            return NULL;
        }
        
        ListNode* s = h;
        ListNode* f = h;
        
        while (f && f->next)
        {
            s = s->next;
            f = f->next->next;
        }
        
        TreeNode* root = new TreeNode(s->val);
        root->left = sortedListToBST(h, s);
        root->right = sortedListToBST(s->next, NULL);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* h, ListNode* t)
    {
        if (h == t)
        {
            return NULL;
        }
        
        ListNode* s = h;
        ListNode* f = h;
        
        while (f != t && f->next != t)
        {
            s = s->next;
            f = f->next->next;
        }
        
        TreeNode* node = new TreeNode(s->val);
        node->left = sortedListToBST(h, s);
        node->right = sortedListToBST(s->next, t);
        
        return node;
    }
};