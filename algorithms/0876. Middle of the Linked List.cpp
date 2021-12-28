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
    ListNode* middleNode(ListNode* head)
    {
        auto t = head;
        auto r = head;
        
        while (r and r->next)
        {
            t = t->next;
            r = r->next->next;
        }
        
        return t;
    }
};