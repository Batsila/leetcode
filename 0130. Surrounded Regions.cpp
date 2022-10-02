class Solution
{
    vector<vector<char>> b;
    vector<vector<bool>> v;
    
public:
    void solve(vector<vector<char>>& board)
    {
        b = board;
        v = vector<vector<bool>>(b.size(), vector<bool>(b[0].size(), false));
        
        for (int i = 0; i < b.size(); ++i)
        {
            dfs(i, 0);
            dfs(i, b[0].size() - 1);
        }
        
        for (int i = 0; i < b[0].size(); ++i)
        {
            dfs(0, i);
            dfs(b.size() - 1, i);
        }
        
        for (int i = 0; i < b.size(); ++i)
        {
            for (int j = 0; j < b[0].size(); ++j)
            {
                if (not v[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    void dfs(int x, int y)
    {
        if (not v[x][y] and b[x][y] == 'O')
        {
            v[x][y] = true;
            
            if (x > 0)
            {
                dfs(x - 1, y);
            }
            
            if (y > 0)
            {
                dfs(x, y - 1);
            }
            
            if (x < b.size() - 1)
            {
                dfs(x + 1, y);
            }
            
            if (y < b[0].size() - 1)
            {
                dfs(x, y + 1);
            }
        }
    }
};