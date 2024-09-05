public class Solution
{
    public int[] MissingRolls(int[] rolls, int mean, int n)
    {
        var totalSum = mean * (rolls.Length + n);
        var firstPartSum = rolls.Sum();
        var remainingSum = totalSum - firstPartSum;

        if (remainingSum >= n && remainingSum <= 6 * n)
        {
            var remainingRolls = new int[n];
            var avgRemainingRoll = remainingSum / n;
            var remainder = remainingSum % n;

            for (int i = 0; i < n; ++i)
            {
                remainingRolls[i] = avgRemainingRoll;

                if (remainder > 0)
                {
                    ++remainingRolls[i];
                    --remainder;
                }
            }

            return remainingRolls;
        }
        else
        {
            return [];
        }
    }
}