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
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        dfs(root, 0);
        
        return ans;
    }
    
    void dfs(Node* node, int h)
    {
        if (node)
        {
            if (ans.size() <= h)
            {
                ans.push_back({node->val});
            }
            else
            {
                ans[h].push_back(node->val);
            }
            
            for (Node* c : node->children)
            {
                dfs(c, h + 1);
            }
        }
    }
};