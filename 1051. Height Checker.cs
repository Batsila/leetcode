public class Solution
{
    public int HeightChecker(int[] heights)
    {
        var expected = heights.Order().ToArray();
        var result = 0;

        for (int i = 0; i < heights.Length; ++i)
        {
            if (heights[i] != expected[i])
            {
                ++result;
            }
        }

        return result;
    }
}