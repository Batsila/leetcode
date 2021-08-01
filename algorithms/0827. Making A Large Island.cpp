class Solution
{
    vector<int> dx = { -1, 0, 1, 0 };
    vector<int> dy = { 0, -1, 0, 1 };
    vector<vector<int>> g;
    int n;
    
public:
    int largestIsland(vector<vector<int>>& grid)
    {
        g = grid;
        n = grid.size();
        
        unordered_map<int, int> m;
        int ind = 2;
        int ans = 0;
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (g[i][j] == 1)
                {
                    int size = dfs(i, j, ind);
                    ans = max(ans, size);
                    m[ind] = size;
                    ++ind;
                }
            }
        }
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (g[i][j] == 0)
                {
                    set<int> s;
                    
                    for (int k = 0; k < 4; ++k)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
            
                        if (nx >= 0
                            and nx < n
                            and ny >= 0
                            and ny < n)
                        {
                            if (g[nx][ny])
                            {
                                s.insert(g[nx][ny]);
                            }
                        }
                    }
                    
                    int c = 1;
                    
                    for (int k : s)
                    {
                        c += m[k];
                    }
                        
                    ans = max(ans, c);
                }
            }
        }
        
        return ans;
    }
    
    int dfs(int x, int y, int ind)
    {
        int size = 1;
        g[x][y] = ind;
        
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0
               and nx < n
               and ny >= 0
               and ny < n)
            {
                if (g[nx][ny] == 1)
                {
                    g[nx][ny] = ind;
                    size += dfs(nx, ny, ind);
                }
            }
        }
        
        return size;
    }
};