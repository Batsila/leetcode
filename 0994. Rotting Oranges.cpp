class Solution
{
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        int f = 0;
        int r = 0;
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ++f;
                }
                
                if (grid[i][j] == 2)
                {
                    ++r;
                    q.push({i, j});
                }
            }
        }
        
        if (r == 0)
        {
            if (f == 0)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        
        int t = -1;
        
        while (!q.empty())
        {
            int qs = q.size();
            
            for (int i = 0; i < qs; ++i)
            {
  
                for (int j = 0; j < 4; ++j)
                {
                    int x = q.front().first + dx[j];
                    int y = q.front().second + dy[j];
                    
                    if (x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        q.push({x, y});
                        --f;
                    }
                }
                
                q.pop();
            }
            
            ++t;
        }
        
        if (f > 0)
        {
            return -1;
        }
        
        return t;
    }
};