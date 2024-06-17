public class Solution
{
    public bool JudgeSquareSum(int c)
    {
        for (int a = 0; a <= Math.Sqrt(c); ++a)
        {
            var b = Math.Sqrt(c - a * a);

            if (b == (int)b)
            {
                return true;
            }
        }

        return false;
    }
}