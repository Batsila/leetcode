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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* l = NULL;
        ListNode* lc = NULL;
        ListNode* g = NULL;
        ListNode* gc = NULL;
        
        ListNode* c = head;
        
        while (c)
        {
            if (c->val < x)
            {
                if (lc)
                {
                    lc->next = c;
                    lc = lc->next;
                }
                else
                {
                    l = c;
                    lc = l;
                }
            }
            else
            {
                if (gc)
                {
                    gc->next = c;
                    gc = gc->next;
                }
                else
                {
                    g = c;
                    gc = g;
                }
            }
            c = c->next;
        }
        
        if (g)
        {
            gc->next = NULL;
        }
        
        if (l)
        {
            lc->next = g;
            
            return l;
        }
        else
        {
            return g;
        }
    }
};