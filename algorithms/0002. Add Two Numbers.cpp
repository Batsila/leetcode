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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ans = NULL;
        ListNode* c = NULL;
        
        int m = 0;
        
        while (l1 != NULL || l2 != NULL)
        {
            int x = l1 != NULL ? l1->val : 0;
            int y = l2 != NULL ? l2->val : 0;
            
            int sum = (x + y + m) % 10;
            m = (x + y + m) / 10;
            
            if (c == NULL)
            {
                c = new ListNode(sum);
                ans = c;
            }
            else
            {
                c->next = new ListNode(sum);
                c = c->next;
            }
            
            l1 = l1 != NULL ? l1->next : NULL;
            l2 = l2 != NULL ? l2->next : NULL;
        }
        
        if (m > 0)
        {
            c->next = new ListNode(m);
        }
        
        return ans;
    }
};