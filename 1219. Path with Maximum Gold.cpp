class Solution
{
public:
    int getMaximumGold(vector<vector<int>>& grid)
    {
        int ans = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                ans = max(ans, dfs(i, j, grid));
            }
        }

        return ans;
    }
    
private:
    int dfs(int x, int y, vector<vector<int>>& grid)
    {
        if (x >= 0 and x < grid.size()
            and y >= 0 and y < grid[x].size()
            and grid[x][y] > 0)
        {
            int temp = grid[x][y];
            grid[x][y] = 0;

            int ans = 0;
            
            ans = max(ans, dfs(x - 1, y, grid));
            ans = max(ans, dfs(x + 1, y, grid));
            ans = max(ans, dfs(x, y - 1, grid));
            ans = max(ans, dfs(x, y + 1, grid));

            grid[x][y] = temp;
            
            return ans + grid[x][y];
        }

        return 0;
    }
};