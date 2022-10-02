/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    unordered_set<ListNode*> s;
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        auto c = headA;
        
        while (c)
        {
            s.insert(c);
            c = c->next;
        }
        
        c = headB;
        
        while (c)
        {
            if (s.find(c) != s.end())
            {
                return c;
            }
            
            c = c->next;
        }
        
        return NULL;
    }
};