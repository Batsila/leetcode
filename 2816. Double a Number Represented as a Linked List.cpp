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
    ListNode* doubleIt(ListNode* head)
    {
        int rem = doubleNext(head);

        if (rem > 0)
        {
            return new ListNode(rem, head);
        }

        return head;
    }

    int doubleNext(ListNode* node)
    {
        if (node)
        {
            int rem = doubleNext(node->next);
            int new_val = node->val * 2 + rem;
            node->val = new_val % 10;

            return new_val / 10;
        }

        return 0;
    }
};