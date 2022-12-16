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
    bool isPalindrome(ListNode* head) 
    {
        if (not head)
        {
            return false;
        }
        
        ListNode* s = head;
        ListNode* f = head;
        
        while (f and f->next)
        {
            s = s->next;
            f = f->next->next;
        }
        
        ListNode* m;
        
        if (f)
        {
            m = s->next;
        }
        else
        {
            m = s;
        }
        
        ListNode* c = m;
        ListNode* n;
        ListNode* p = NULL;
        
        while (c)
        {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        
        while (p)
        {
            if (head->val != p->val)
            {
                return false;
            }
            
            head= head->next;
            p = p->next;
        }
        
        return true;  
    }
};