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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* c = head;
        
        int size = 0;
        
        while (c)
        {
            c = c->next;
            ++size;
        }
        
        int m = size - n;
        
        if (m == 0)
        {
            return head->next;
        }
        
        c = head;
        
        for (int i = 1; i < m; ++i)
        {
            c = c->next;
        }
        
        c->next = c->next ? c->next->next : NULL;
        
        return head;
    }
};