class Solution
{
    int dx[9] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };
    int dy[9] = { -1, -1, 0, 1, 1, 1, 0, -1, 0 };
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));

        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 1; j < n - 1; ++j)
            {
                for (int k = 0; k < 9; ++k)
                {
                    ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i + dx[k]][j + dy[k]]);
                }
            }
        }

        return ans;
    }
};