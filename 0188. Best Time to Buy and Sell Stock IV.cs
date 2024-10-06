public class Solution
{
    public int MaxProfit(int k, int[] prices)
    {
        var minPrice = Enumerable.Range(0, k).Select(x => int.MaxValue).ToArray();
        var maxProfit = Enumerable.Range(0, k).Select(x => 0).ToArray();

        foreach (var price in prices)
        {
            for (int i = 0; i < k; ++i)
            {
                var previousProfit = i > 0 ? maxProfit[i - 1] : 0;
                minPrice[i] = Math.Min(minPrice[i], price - previousProfit);
                maxProfit[i] = Math.Max(maxProfit[i], price - minPrice[i]);
            }
        }

        return maxProfit[^1];
    }
}