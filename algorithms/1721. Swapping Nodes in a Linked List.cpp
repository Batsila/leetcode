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
class Solution
{
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode* l = head;
        ListNode* r = head;
        ListNode* c = head;
        
        int ind = 1;
        
        while (c)
        {
            if (ind < k)
            {
                l = l->next;
            }
            
            if (ind > k)
            {
                r = r->next;
            }
            
            c = c->next;
            ++ind;
        }
        
        int t = l->val;
        l->val = r->val;
        r->val = t;
        
        return head; 
    }
};