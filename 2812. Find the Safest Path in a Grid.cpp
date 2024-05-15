class Solution
{
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
public:
    int maximumSafenessFactor(vector<vector<int>>& grid)
    {
        int n = grid.size();
        
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                else
                {
                    grid[i][j] = -1;
                }
            }
        }

        while (not q.empty())
        {
            int count = q.size();

            while (count > 0)
            {
                auto current = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i)
                {
                    int x = current.first + dx[i];
                    int y = current.second + dy[i];

                    if (x >= 0 and x < n and y >= 0 and y < n and grid[x][y] == -1)
                    {
                        grid[x][y] = grid[current.first][current.second] + 1;
                        q.push({x, y});
                    }
                }

                -- count;
            }
        }

        priority_queue<vector<int>> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = -1;

        while (not pq.empty())
        {
            auto current = pq.top();
            pq.pop();

            if (current[1] == n - 1 and current[2] == n - 1)
            {
                return current[0];
            }
            else
            {
                for (int i = 0; i < 4; ++i)
                {
                    int x = current[1] + dx[i];
                    int y = current[2] + dy[i];

                    if (x >= 0 and x < n and y >= 0 and y < n and grid[x][y] != -1)
                    {
                        pq.push({min(current[0], grid[x][y]), x, y});
                        grid[x][y] = -1;
                    }
                }
            }
        }

        return -1;
    }
};