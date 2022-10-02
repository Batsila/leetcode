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
    ListNode* deleteDuplicates(ListNode* head)
    {
        auto ans = new ListNode(0, head);
        
        auto c = head;
        auto p = ans;
        
        while (c)
        {
            if (c->next and c->next->val == c->val)
            {
                while (c->next and c->next->val == c->val)
                {
                    c = c->next;
                }
                
                p->next = c->next;
            }
            else
            {
                p = p->next;
            }
            
            c = c->next;
        }
        
        return ans->next;
    }
};