public class Solution
{
    public int SpecialArray(int[] nums)
    {
        var n = nums.Length;
        var prefixCount = new int[n + 1];

        foreach (var num in nums)
        {
            ++prefixCount[Math.Min(n, num)];
        }

        var currentCount = 0;

        for (int x = n; x > 0; --x)
        {
            currentCount += prefixCount[x];

            if (currentCount == x)
            {
                return x;
            }
        }

        return -1;
    }
}