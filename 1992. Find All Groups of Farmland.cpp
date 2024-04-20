class Solution
{
    int r2;
    int c2;
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land)
    {
        vector<vector<int>> ans;

        for (int i = 0; i < land.size(); ++i)
        {
            for (int j = 0; j < land[i].size(); ++j)
            {
                if (land[i][j] == 1)
                {
                    r2 = INT_MIN;
                    c2 = INT_MIN;
                    dfs(i, j, land);

                    if (r2 != INT_MIN)
                    {
                        ans.push_back({ i, j, r2, c2 });
                    }
                }
            }
        }

        return ans;
    }

    void dfs(int x, int y, vector<vector<int>>& land)
    {
        if (x >= 0 
            and x < land.size() 
            and y >= 0 
            and y < land[x].size() 
            and land[x][y] == 1)
        {
            land[x][y] = 0;
            r2 = max(r2, x);
            c2 = max(c2, y);

            dfs(x + 1, y, land);
            dfs(x, y + 1, land);
        }
    }
};