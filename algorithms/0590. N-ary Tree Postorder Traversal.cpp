/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
    vector<int> ans;
public:
    vector<int> postorder(Node* root) 
    {
        dfs(root);
        
        return ans;
    }
    
    void dfs(Node* node)
    {
        if (node)
        {
            for (auto c : node->children)
            {
               dfs(c); 
            }
            
            ans.push_back(node->val);
        }
    }
};