public class Solution
{
    public int MinPathSum(int[][] grid)
    {
        for (int i = 0; i < grid.Length; ++i)
        {
            for (int j = 0; j < grid[i].Length; ++j)
            {
                var minPath = int.MaxValue;

                if (i != 0 && j != 0)
                {
                    grid[i][j] += Math.Min(grid[i - 1][j], grid[i][j - 1]);
                }
                else if (i != 0)
                {
                    grid[i][j] += grid[i - 1][j];
                }
                else if (j != 0)
                {
                    grid[i][j] += grid[i][j - 1];
                }
            }
        }

        return grid[^1][^1];
    }
}