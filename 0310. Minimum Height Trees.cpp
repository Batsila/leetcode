class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if (n == 1)
        {
            return { 0 };
        }

        vector<unordered_set<int>> graph(n, unordered_set<int>());

        for (auto edge : edges)
        {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        vector<int> leaves;

        for (int i = 0; i < n; ++i)
        {
            if (graph[i].size() == 1)
            {
                leaves.push_back(i);
            }
        }

        int count = 0;

        while (n - count > 2)
        {
            count += leaves.size();
            vector<int> new_leaves;

            for (int leaf : leaves)
            {
                int neighbor = *graph[leaf].begin();
                graph[neighbor].erase(leaf);

                if (graph[neighbor].size() == 1)
                {
                    new_leaves.push_back(neighbor);
                }
            }

            leaves = new_leaves;
        }

        return leaves;
    }
};