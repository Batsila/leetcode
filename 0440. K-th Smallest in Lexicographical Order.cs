public class Solution
{
    public int FindKthNumber(int n, int k)
    {
        var current = 1;
        --k;

        while (k > 0)
        {
            var steps = DeltaSteps(n, current, current + 1);

            if (steps <= k)
            {
                ++current;
                k -= steps;
            }
            else
            {
                current *= 10;
                --k;
            }
        }

        return current;
    }

    private int DeltaSteps(
        int n,
        long prefix1,
        long prefix2)
    {
        var delta = 0;

        while (prefix1 <= n)
        {
            delta += (int)(Math.Min(n + 1, prefix2) - prefix1);
            prefix1 *= 10;
            prefix2 *= 10;
        }

        return delta;
    }
}