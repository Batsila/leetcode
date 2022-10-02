class Solution
{
    vector<vector<int>> g;
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        g = grid;
        int ans = 0;
        
        for (int i = 0; i < g.size(); ++i)
        {
            for (int j = 0; j < g[0].size(); ++j)
            {
                ans += foo(i, j);
            }
        }
        
        return ans;
    }
    
    int foo(int i, int j)
    {
        if (g[i][j])
        {
            int p = 0;
            
            for (int k = 0; k < 4; ++k)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                
                if (x >= 0 and x < g.size() and y >= 0 and y < g[0].size())
                {
                    p += g[x][y] ? 0 : 1;
                }
                else
                {
                    ++p;
                }
            }
            
            return p;
        }
        
        return 0;
    }
};