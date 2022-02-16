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
    ListNode* swapPairs(ListNode* head)
    {
        if (not head or not head->next)
        {
            return head;
        }
        
        auto new_head = head->next;
        head->next = swapPairs(head->next->next);
        new_head->next = head;
        
        return new_head;
    }
};