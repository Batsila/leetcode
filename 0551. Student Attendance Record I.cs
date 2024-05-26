public class Solution
{
    public bool CheckRecord(string s)
    {
        var absentDays = 0;
        var lateDays = 0;

        foreach (var c in s)
        {
            if (c == 'L')
            {
                ++lateDays;

                if (lateDays == 3)
                {
                    return false;
                }
            }
            else
            {
                lateDays = 0;

                if (c == 'A')
                {
                    ++absentDays;

                    if (absentDays == 2)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
}