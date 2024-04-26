class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        for (int i = 1; i < grid.size(); ++i)
        {
            priority_queue<int, vector<int>, greater<int>> pq(grid[i - 1].begin(), grid[i - 1].end());
            int min_item = pq.top();
            pq.pop();
            int second_min_item = pq.top();

            for (int j = 0; j < grid[i].size(); ++j)
            {
                grid[i][j] += grid[i - 1][j] == min_item ? second_min_item : min_item;
            }
        }

        return *min_element(grid[grid.size() - 1].begin(), grid[grid.size() - 1].end());
    }
};