/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
    map<int, vector<Node*>> m;
public:
    Node* connect(Node* root)
    {
        dfs(root, 0);
        
        for (auto p : m)
        {
            for (int i = 0; i < p.second.size() - 1; ++i)
            {
                p.second[i]->next = p.second[i + 1];
            }
        }
        
        return root;
    }
    
    void dfs(Node* node, int l)
    {
        if (node)
        {
            m[l].push_back(node);
            dfs(node->left, l + 1);
            dfs(node->right, l + 1);
        }
    }
};