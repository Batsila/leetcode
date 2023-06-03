class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        vector<vector<int>> tree(n, vector<int>());

        for (int i = 0; i < n; ++i)
        {
            if (manager[i] != -1)
            {
                tree[manager[i]].push_back(i);
            }
        }

        return dfs(headID, tree, informTime);
    }

    int dfs(int v, vector<vector<int>>& tree, vector<int>& informTime, int curTime = 0)
    {
        int ans = curTime;

        for (int u : tree[v])
        {
            ans = max(ans, dfs(u, tree, informTime, curTime + informTime[v]));
        }

        return ans;
    }
};