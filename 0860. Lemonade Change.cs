public class Solution
{
    public bool LemonadeChange(int[] bills)
    {
        var fiveCount = 0;
        var tenCount = 0;

        foreach (var bill in bills)
        {
            if (bill == 5)
            {
                ++fiveCount;
            }
            else if (bill == 10)
            {
                if (fiveCount > 0)
                {
                    ++tenCount;
                    --fiveCount;
                }
                else
                {
                    return false;
                }
            }
            else if (bill == 20)
            {
                if (tenCount > 0 && fiveCount > 0)
                {
                    --tenCount;
                    --fiveCount;
                }
                else if (fiveCount >= 3)
                {
                    fiveCount -= 3;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }
}