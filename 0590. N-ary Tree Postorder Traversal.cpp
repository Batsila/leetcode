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
public:
    vector<int> postorder(Node* root)
    {
        vector<int> result;
        postorder_traversal(root, result);

        return result;
    }
private:
    void postorder_traversal(Node* node, vector<int>& result)
    {
        if (node)
        {
            for (auto child : node->children)
            {
                postorder_traversal(child, result);
            }

            result.push_back(node->val);
        }
    }
};