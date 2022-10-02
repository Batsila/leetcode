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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (not head)
        {
            return NULL;
        }
        
        ListNode* p = NULL;
        ListNode* c = head;
        
        while (left > 1)
        {
            p = c;
            c = c->next;
            --left;
            --right;
        }
        
        ListNode* e = c;
        ListNode* pe = p;
        ListNode* n = NULL;

        while (right > 0)
        {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
            --right;
        }
        
        if (pe)
        {
            pe->next = p;
        }
        else
        {
            head = p;
        }
        
        e->next = c;
        
        return head;
    }
};