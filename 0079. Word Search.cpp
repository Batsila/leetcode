class Solution
{
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
    string w;
    vector<vector<char>> b;
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        w = word;
        b = board;
        for (int i = 0; i < b.size(); ++i)
        {
            for (int j = 0; j < b[0].size(); ++j)
            {     
                if (dfs(i, j, string(1, b[i][j])))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(int i, int j, string c)
    {     
        if (c == w)
        {
            return true;
        }
        
        char t = b[i][j];
        b[i][j] = '-';
        
        if (c.size() < w.size() and w.substr(0, c.size()) == c)
        {
            for (int k = 0; k < 4; ++k)
            {
                int x = i + dx[k];
                int y = j + dy[k];
            
                if (x >= 0 and x < b.size() and y >= 0 and y < b[0].size() and b[x][y] != '-')
                {
                    if (dfs(x, y, c + b[x][y]))
                    {
                        return true;
                    }
                }
            }
        }
        
        b[i][j] = t;
        
        return false;
    }
};