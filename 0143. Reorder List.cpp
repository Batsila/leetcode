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
        vector<ListNode*> nodes;
        
        ListNode* c = head;
        
        while (c)
        {
            nodes.push_back(c);
            c = c->next;
        }
        
        int l = 0;
        int r = nodes.size() - 1;
        c = head;
        
        for (int i = 0; i < nodes.size(); ++i)
        {
            if (i % 2 == 0)
            {
                c->next = nodes[l];
                ++l;
            }
            else
            {
                c->next = nodes[r];
                --r;
            }
            
            c = c->next;
        }
        
        c->next = NULL;
    }
};