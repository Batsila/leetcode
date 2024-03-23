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
    void reorderList(ListNode* head)
    {
        // find mid
        auto fast = head;
        auto slow = head;

        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse 2nd half
        auto current = slow->next; // mid
        ListNode* previous = NULL;

        while (current)
        {
            auto temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }

        // merge
        slow->next = NULL;
        auto mid = previous;
        current = head;

        while (mid)
        {
            auto t1 = current->next;
            current->next = mid;
            auto t2 = mid->next;
            current->next->next = t1;
            mid = t2;
            current = current->next->next;
        }
    }
};