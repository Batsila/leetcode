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
    ListNode* sortList(ListNode* head)
    {
        vector<int> v;
        
        ListNode* c = head;
        
        while (c)
        {
            v.push_back(c->val);
            c = c->next;
        }
        
        sort(v.begin(), v.end());
        
        c = head;
        int ind = 0;
        
        while (c)
        {
            c->val = v[ind];
            ++ind;
            c = c->next;
        }
        
        return head;
    }
};