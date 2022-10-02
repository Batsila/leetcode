class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                int ind = grid[i].size() * i + j;
                int nind = (ind + k) % (grid.size() * grid[0].size());
                
                int r = nind / grid[0].size();
                int c = nind % grid[0].size();
                
                ans[r][c] = grid[i][j];
            }
        }
        
        return ans;
    }
};