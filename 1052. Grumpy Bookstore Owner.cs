public class Solution
{
    public int MaxSatisfied(int[] customers, int[] grumpy, int minutes)
    {
        var currentCount = customers.Zip(grumpy, (c, g) => g == 0 ? c : 0).Sum();
        var end = 0;

        while (end < minutes)
        {
            if (grumpy[end] == 1)
            {
                currentCount += customers[end];
            }

            ++end;
        }

        var result = currentCount;

        while (end < customers.Length)
        {
            if (grumpy[end - minutes] == 1)
            {
                currentCount -= customers[end - minutes];
            }

            if (grumpy[end] == 1)
            {
                currentCount += customers[end];
            }

            result = Math.Max(result, currentCount);
            ++end;
        }

        return result;
    }
}