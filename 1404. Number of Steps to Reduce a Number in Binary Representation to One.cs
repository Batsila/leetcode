public class Solution
{
    public int NumSteps(string s)
    {
        var result = 0;
        var rem = 0;

        for (int i = s.Length - 1; i > 0; --i)
        {
            if (s[i] - '0' != rem)
            {
                result += 2;
                rem = 1;
            }
            else
            {
                ++result;
            }
        }

        return result + rem;
    }
}