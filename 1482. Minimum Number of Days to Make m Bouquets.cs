public class Solution
{
    public int MinDays(int[] bloomDay, int m, int k)
    {
        if ((long)m * k <= bloomDay.Length)
        {
            var left = 0;
            var right = bloomDay.Max();
            var result = int.MaxValue;

            while (left <= right)
            {
                var mid = (left + right) / 2;

                if (CanCreateBouquets(bloomDay, m, k, mid))
                {
                    result = Math.Min(result, mid);
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            return result;
        }
        
        return -1;
    }

    private bool CanCreateBouquets(int[] bloomDays, int m, int k, int day)
    {
        var bouquetCount = 0;
        var flowersInBouquet = 0;

        foreach (var bloomDay in bloomDays)
        {
            if (bloomDay <= day)
            {
                ++flowersInBouquet;

                if (flowersInBouquet == k)
                {
                    ++bouquetCount;
                    flowersInBouquet = 0;
                }
            }
            else
            {
                flowersInBouquet = 0;
            }
        }

        return bouquetCount >= m;
    }
}