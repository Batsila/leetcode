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
    ListNode* deleteMiddle(ListNode* head)
    {
        if (head->next)
        {
            auto s = head;
            auto f = head->next->next;
            
            while (f and f->next)
            {
                s = s->next;
                f = f->next->next;
            }
            
            s->next = s->next->next;
            
            return head;
        }
        
        return NULL;
    }
};