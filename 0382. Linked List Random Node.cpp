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
    ListNode* h;
    int n = 0;
public:
    Solution(ListNode* head)
    {
        h = head;
        
        ListNode* c = h;
        
        while (c)
        {
            ++n;
            c = c->next;
        }
    }
    
    int getRandom()
    {
        int ind = rand() % n;
        ListNode* c = h;
        
        while (ind > 0)
        {
            c = c->next;
            --ind;
        }
        
        return c->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */