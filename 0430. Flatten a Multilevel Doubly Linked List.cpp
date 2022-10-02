/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
    vector<int> v;
    
public:
    Node* flatten(Node* head)
    {
        dfs(head);
        
        if (v.size() > 0)
        {
            Node* new_head = new Node();
            new_head->val = v[0];
            
            Node* c = new_head;
            
            for (int i = 1; i < v.size(); ++i)
            {
                Node* t = new Node;
                t->val = v[i];
                t->prev = c;
                c->next = t;
                c = t;
            }
            
            return new_head;
        }
        
        return NULL;
    }
    
    void dfs(Node* node)
    {
        if (node)
        {
            v.push_back(node->val);
            
            dfs(node->child);
            dfs(node->next);
        }
    }
};