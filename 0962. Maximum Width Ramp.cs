public class Solution
{
    public int MaxWidthRamp(int[] nums)
    {
        var indexes = nums.Select((x, ind) => (x, ind)).OrderBy(x => x.Item1).ToArray();
        var minIndex = nums.Length;
        var maxWidth = 0;

        foreach (var index in indexes)
        {
            maxWidth = Math.Max(maxWidth, index.Item2 - minIndex);
            minIndex = Math.Min(minIndex, index.Item2);
        }

        return maxWidth;
    }
}