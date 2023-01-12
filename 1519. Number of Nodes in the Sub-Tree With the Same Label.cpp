class Solution
{
    string l;
    vector<vector<int>> g;
    vector<int> ans;
    vector<bool> used;
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
    {
        l = labels;
        used = vector<bool>(n);
        ans = vector<int>(n, 0);
        g = vector(n, vector<int>());

        for (auto edge : edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        dfs(0);

        return ans;
    }

    vector<int> dfs(int v)
    {
        used[v] = true;
        vector<int> c(26, 0);
        ++c[l[v] - 'a'];

        for (int u : g[v])
        {
            if (not used[u])
            {
                vector<int> cc = dfs(u);

                for (int i = 0; i < 26; ++i)
                {
                    c[i] += cc[i];
                }
            }
        }

        ans[v] = c[l[v] - 'a'];

        return c;
    }
};