public class Solution
{
    public IList<int> LuckyNumbers (int[][] matrix)
    {
        var minInRow = Enumerable.Range(0, matrix.Length).Select(x => int.MaxValue).ToArray();
        var maxInColumn = Enumerable.Range(0, matrix[0].Length).Select(x => int.MinValue).ToArray();

        for (int i = 0; i < matrix.Length; ++i)
        {
            for (int j = 0; j < matrix[0].Length; ++j)
            {
                minInRow[i] = Math.Min(minInRow[i], matrix[i][j]);
                maxInColumn[j] = Math.Max(maxInColumn[j], matrix[i][j]);
            }
        }

        var result = new List<int>();

        for (int i = 0; i < matrix.Length; ++i)
        {
            for (int j = 0; j < matrix[0].Length; ++j)
            {
                if (matrix[i][j] == minInRow[i] && matrix[i][j] == maxInColumn[j])
                {
                    result.Add(matrix[i][j]);
                }
            }
        }

        return result;
    }
}