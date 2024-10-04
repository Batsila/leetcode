public class Solution
{
    public int MaxProfit(int[] prices)
    {
        var profit = 0;
        var minPrice = prices[0];

        foreach (var price in prices[1..])
        {
            profit = Math.Max(profit, price - minPrice);
            minPrice = Math.Min(minPrice, price);
        }

        return profit;
    }
}