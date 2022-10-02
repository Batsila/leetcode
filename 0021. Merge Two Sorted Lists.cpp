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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if (not l1)
        {
           return l2; 
        }
            
        if (not l2)
        {
            return l1;
        }
         
        ListNode* ans = new ListNode(42);
        ListNode* t = ans;
        
        while (l1 and l2)
        {
            if (l1->val < l2->val)
            {
                t->next = l1;
                l1 = l1->next;
            }
            else
            {
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
        }
        
        if (l1)
        {
            t->next = l1;
        }
        
        if (l2)
        {
            t->next = l2;
        }
        
        return ans->next;
    }
};