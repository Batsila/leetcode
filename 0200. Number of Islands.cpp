class Solution
{
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int ans = 0;
        
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++ans;
                    dfs(i, j, grid);
                }
            }
        }
        
        return ans;
    }
    
    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        if (x < 0 
            or x >= grid.size() 
            or y < 0 
            or y >= grid[0].size() 
            or grid[x][y] == '0')
        {
            return;
        }
        
        grid[x][y] = '0';
        
        for (int i = 0; i < 4; ++i)
        {
            dfs(x + dx[i], y + dy[i], grid);
        }
    }
};