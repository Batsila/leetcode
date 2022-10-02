class Solution
{
public:
    int shortestPath(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> v(m, vector<int>(n, -1));
        queue<vector<int>> q;
        
        q.push({0, 0, 0, k});
        
        while (not q.empty())
        {
            vector<int> c = q.front();
            q.pop();
            
            if (c[0] == m - 1 and c[1] == n - 1)
            {
                return c[2];
            }
            
            if (c[0] >= 0 and c[0] < m
               and c[1] >= 0 and c[1] < n)
            {
                if (grid[c[0]][c[1]])
                {
                    --c[3];
                }
                
                if (c[3] >= 0)
                {
                    if (v[c[0]][c[1]] == -1 or v[c[0]][c[1]] < c[3])
                    {
                        v[c[0]][c[1]] = c[3];
                        
                        q.push({c[0] + 1, c[1], c[2] + 1, c[3]});
                        q.push({c[0] - 1, c[1], c[2] + 1, c[3]});
                        q.push({c[0], c[1] + 1, c[2] + 1, c[3]});
                        q.push({c[0], c[1] - 1, c[2] + 1, c[3]});
                    }
                }
            }
        }
        
        return -1;
    }
};