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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (not head)
        {
            return NULL;
        }
        
        int n = 0;
        auto c = head;
        
        while (c)
        {
            ++n;
            c = c->next;
        }
        
        int r = n - k % n;
        
        if (r == n)
        {
            return head;
        }
        
        c = head;
        ListNode* p = NULL;
        
        while (r)
        {
            --r;
            p = c;
            c = c->next;
        }
        
        if (p)
        {
            p->next = NULL;
        }
        
        auto ans = c;
        
        while (c)
        {
            p = c;
            c = c->next;
        }
        
        p->next = head;
        
        return ans;
    }
};