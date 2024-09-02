public class Solution
{
    public int ChalkReplacer(int[] chalk, int k)
    {
        var sum = chalk.Select(x => (long)x).Sum();
        var longK = (long)k;
        longK %= sum;

        for (int i = 0; i < chalk.Length; ++i)
        {
            if (longK < chalk[i])
            {
                return i;
            }

            longK -= chalk[i];
        }

        return -1;
    }
}