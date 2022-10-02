/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
    unordered_map<Node*, Node*> m;
public:
    Node* copyRandomList(Node* head)
    {
        auto c = head;
        Node* np = NULL;
        
        while (c)
        {
            Node* n = new Node(c->val);
            m[c] = n;
            
            if (np)
            {
                np->next = n;
            }
            
            np = n;
            c = c->next;
        }
        
        c = head;
        Node* nc = m[head];
        
        while (c)
        {
            nc->random = m[c->random];
            c = c->next;
            nc = nc->next;
        }
        
        return m[head];
    }
};