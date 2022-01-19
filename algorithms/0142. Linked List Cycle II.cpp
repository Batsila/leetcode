/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* s = head;
        ListNode* f = head;
        
        while (f and f->next)
        {
            s = s->next;
            f = f->next->next;
            
            if (s == f)
            {
                break;
            }
        }
        
        if (not f or not f->next)
        {
            return NULL;
        }
        
        ListNode* ans = head;
        
        while (ans != s)
        {
            ans = ans->next;
            s = s->next;
        }
        
        return ans;
    }
};