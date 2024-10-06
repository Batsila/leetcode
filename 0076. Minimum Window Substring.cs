public class Solution
{
    public string MinWindow(string s, string t)
    {
        var frequencies = new int[58];

        foreach (var c in t)
        {
            ++frequencies[c - 'A'];
        }

        var l = 0;
        var r = 0;
        var currentFrequencies = new int[58];
        string result = null;

        while (r < s.Length)
        {
            var current = s[r] - 'A';
            ++currentFrequencies[current];

            while (ContainsEnough(currentFrequencies, frequencies))
            {
                if (result == null || r - l + 1 < result.Length)
                {
                    result = s[l..(r + 1)];
                }

                --currentFrequencies[s[l] - 'A'];
                ++l;
            }

            ++r;
        }

        return result != null ? result : string.Empty;
    }

    private static bool ContainsEnough(int[] current, int[] target)
    {
        for (int i = 0; i < 58; ++i)
        {
            if (current[i] < target[i])
            {
                return false;
            }
        }

        return true;
    }
}