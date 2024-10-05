public class Solution
{
    public bool CheckInclusion(string s1, string s2)
    {
        var frequencies = new int[26];

        foreach (var c in s1)
        {
            ++frequencies[c - 'a'];
        }

        var l = 0;
        var r = 0;
        var currentFrequencies = new int[26];

        while (r < s2.Length)
        {
            var current = s2[r] - 'a';
            ++currentFrequencies[current];

            while (currentFrequencies[current] > frequencies[current])
            {
                --currentFrequencies[s2[l] - 'a'];
                ++l;
            }

            if (frequencies.SequenceEqual(currentFrequencies))
            {
                return true;
            }

            ++r;
        }

        return false;
    }
}