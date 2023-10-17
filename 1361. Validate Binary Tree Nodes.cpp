class Solution
{
    int get_root(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        unordered_set<int> children;
        children.insert(leftChild.begin(), leftChild.end());
        children.insert(rightChild.begin(), rightChild.end());
    
        for (int i = 0; i < n; ++i)
        {
            if (children.find(i) == children.end())
            {
                return i;
            }
        }
    
        return -1;
    }

    bool dfs(int v, vector<int>& leftChild, vector<int>& rightChild, vector<bool> &is_used)
    {
        is_used[v] = true;

        if (leftChild[v] != -1)
        {
            if (is_used[leftChild[v]] or not dfs(leftChild[v], leftChild, rightChild, is_used))
            {
                return false;
            }
        }

        if (rightChild[v] != -1)
        {
            if (is_used[rightChild[v]] or not dfs(rightChild[v], leftChild, rightChild, is_used))
            {
                return false;
            }
        }

        return true;
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        int root = get_root(n, leftChild, rightChild);
        vector<bool> is_used(n, false);

        if (root != -1)
        {
            bool res = dfs(root, leftChild, rightChild, is_used);

            if (res)
            {
                for (bool used : is_used)
                {
                    if (not used)
                    {
                        return false;
                    }
                }

                return true;
            }
        }

        return false;
    }
};