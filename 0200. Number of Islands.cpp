class Solution
{
    vector<vector<char>> g;
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int ans = 0;
        g = grid;
        
        for (int i = 0; i < g.size(); ++i)
        {
            for (int j = 0; j < g[i].size(); ++j)
            {
                if (g[i][j] == '1')
                {
                    ++ans;
                    dfs(i, j);
                }
            }
        }
        
        return ans;
    }
    
    void dfs(int x, int y)
    {
        if (x < 0 
            or x >= g.size() 
            or y < 0 
            or y >= g[0].size() 
            or g[x][y] == '0')
        {
            return;
        }
        
        g[x][y] = '0';
        
        for (int i = 0; i < 4; ++i)
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
};