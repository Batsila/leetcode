class Solution
{
    vector<vector<int>> grid;
    vector<vector<bool>> used;
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        this->grid = grid;
        this->used = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), 0));
        
        int ans = 0;
        
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                ans = max(ans, dfs(i, j));
            }
        }
        
        return ans;
    }
    
    int dfs(int i, int j)
    {
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or used[i][j] or not grid[i][j])
        {
            return 0;
        }
        
        used[i][j] = 1;
        
        return 1 + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1);
    }
};