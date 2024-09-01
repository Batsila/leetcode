public class Solution
{
    public int[][] Construct2DArray(int[] original, int m, int n)
    {
        if (m * n == original.Length)
        {
            var result = Enumerable.Range(0, m).Select(x => new int[n]).ToArray();

            for (int i = 0; i < original.Length; ++i)
            {
                result[i / n][i % n] = original[i];
            }

            return result;
        }

        return [];
    }
}