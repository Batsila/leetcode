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
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        ListNode* c = head;
        int n = 0;
        
        while (c != NULL)
        {
            ++n;
            c = c->next;
        }
        
        int pn = n / k;
        int r = n % k;
        
        vector<ListNode*> ans(k, NULL);
        c = head;
        
        for (int i = 0; i < k; ++i)
        {
            ListNode* ch = c;
            
            for (int j = 0; j < pn + (i < r ? 1 : 0) - 1; ++j)
            {
                if (c != NULL)
                {
                    c = c->next;
                }
            }
            
            if (c != NULL)
            {
                ListNode* p = c;
                c = c->next;
                p->next = NULL;
            }
            
            ans[i] = ch;
        }
        
        return ans;
    }
};