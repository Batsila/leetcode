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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* dummy = new ListNode(420, head);
        
        ListNode* p = dummy;
        ListNode* c = head;
        
        while (c)
        {
            if (c->val == val)
            {
                p->next = c->next;
            }
            else
            {
                p = c;
            }
            
            c = c->next;
        }
        
        return dummy->next;
    }
};