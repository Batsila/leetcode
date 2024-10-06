public class Solution
{
    public int MaxProfit(int[] prices)
    {
        var minPrice1 = int.MaxValue;
        var profit1 = 0;
        var minPrice2 = int.MaxValue;
        var profit2 = 0;

        foreach (var price in prices)
        {
            minPrice1 = Math.Min(minPrice1, price);
            profit1 = Math.Max(profit1, price - minPrice1);
            minPrice2 = Math.Min(minPrice2, price - profit1);
            profit2 = Math.Max(profit2, price - minPrice2);
        }

        return profit2;
    }
}