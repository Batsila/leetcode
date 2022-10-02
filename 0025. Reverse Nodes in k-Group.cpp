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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* c = head;
        
        int n = 0;
        
        while (c)
        {
            c = c->next;
            ++n;
        }
        
        int pn = n / k;
        
        c = head;
        
        ListNode* pp = NULL;
        ListNode* ans = NULL;
        
        for (int j = 0; j < pn; ++j)
        {
            ListNode* cc = c;
            ListNode* p = NULL;
            
            for (int i = 0; i < k; ++i)
            {
                ListNode* t = c->next;
                c->next = p;
                p = c;
                c = t;
            }
            
            if (j == 0)
            {
                ans = p;
            }
            
            if (pp)
            {
                pp->next = p;
            }
            
            pp = cc;
        }
        
        if (pp)
        {
            pp->next = c;
        }
        
        return ans;
    }
};