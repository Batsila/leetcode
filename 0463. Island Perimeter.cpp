class Solution
{
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int ans = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if (x < 0 or x >= grid.size()
                            or y < 0 or y >= grid[i].size()
                            or grid[x][y] == 0)
                        {
                            ++ans;
                        }
                    }
                }
            }
        }

        return ans;
    }
};