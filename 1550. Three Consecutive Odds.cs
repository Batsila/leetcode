public class Solution
{
    public bool ThreeConsecutiveOdds(int[] arr)
    {
        var oddsCount = 0;

        foreach (var num in arr)
        {
            if (num % 2 == 1)
            {
                ++oddsCount;
            }
            else
            {
                oddsCount = 0;
            }

            if (oddsCount >= 3)
            {
                return true;
            }
        }

        return false;
    }
}