public class Solution
{
    public int LongestPalindrome(string s)
    {
        var frequencies = new int[52];

        foreach (var c in s)
        {
            if (c >= 'a')
            {
                ++frequencies[c - 'a' + 26];
            }
            else
            {
                ++frequencies[c - 'A'];
            }
        }

        var result = 0;
        var isOdd = false;

        for (int i = 0; i < 52; ++i)
        {
            result += frequencies[i] / 2;

            if (frequencies[i] % 2 == 1)
            {
                isOdd = true;
            }
        }

        return isOdd ? result * 2 + 1 : result * 2;
    }
}