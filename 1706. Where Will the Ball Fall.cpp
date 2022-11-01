class Solution
{
    vector<vector<int>> g;
public:
    vector<int> findBall(vector<vector<int>>& grid)
    {
        g = grid;
        vector<int> ans;
        
        for (int i = 0; i < g[0].size(); ++i)
        {
            ans.push_back(dfs(0, i));
        }
        
        return ans;
    }
    
    int dfs(int r, int c)
    {
        if (r == g.size())
        {
            return c;
        }
        
        int nc = c + g[r][c];
        
        if (nc >= 0
            and nc < g[r].size()
            and g[r][nc] == g[r][c])
        {
            return dfs(r + 1, nc);
        }
        
        return -1;
    }
};