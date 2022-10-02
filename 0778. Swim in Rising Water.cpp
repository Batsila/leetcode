class Solution
{
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
public:
    int swimInWater(vector<vector<int>>& grid)
    {
        vector<vector<int>> v(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        queue<vector<int>> q;
        
        v[0][0] = grid[0][0];
        q.push({ 0, 0 });
        
        while (not q.empty())
        {
            auto c = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i)
            {
                int x = c[0] + dx[i];
                int y = c[1] + dy[i];
                
                if (x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size())
                {
                    int tv = max(v[c[0]][c[1]], grid[x][y]);
                    
                    if (tv < v[x][y])
                    {
                        q.push({ x, y });
                        v[x][y] = tv;
                    }
                }
            }
        }
        
        return v[grid.size() - 1][grid[0].size() - 1];
    }
};