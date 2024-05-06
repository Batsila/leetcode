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
    ListNode* removeNodes(ListNode* head)
    {
        mark_to_delete(head);

        ListNode* new_head = NULL;
        ListNode* current = head;
        ListNode* new_current = NULL;

        while (current)
        {
            if (current->val > 0)
            {
                if (new_head)
                {
                    new_current->next = current;
                    new_current = new_current->next;
                }
                else
                {
                    new_head = current;
                    new_current = new_head;
                }
            }

            current = current->next;
        }

        return new_head;
    }

    int mark_to_delete(ListNode* node)
    {
        if (node)
        {
            int max_next = mark_to_delete(node->next);

            if (node->val < max_next)
            {
                node->val *= -1;
            }

            return max(max_next, node->val);
        }

        return -1;
    }
};