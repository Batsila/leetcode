class Solution
{
public:
    int matrixScore(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = (1 << (m - 1)) * n;

        for (int i = 1; i < m; ++i)
        {
            int ones_count = 0;

            for (int j = 0; j < n; ++j)
            {
                if ((grid[j][i] == 1 and grid[j][0] == 1)
                    or (grid[j][i] == 0 and grid[j][0] == 0))
                {
                    ++ones_count;
                }
            }

            ans += (1 << (m - 1 - i)) * max(n - ones_count, ones_count);
        }

        return ans;
    }
};