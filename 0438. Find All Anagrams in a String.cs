public class Solution
{
    public IList<int> FindAnagrams(string s, string p)
    {
        var frequencies = new int[26];

        foreach (var c in p)
        {
            ++frequencies[c - 'a'];
        }

        var l = 0;
        var r = 0;
        var currentFrequencies = new int[26];
        var result = new List<int>();

        while (r < s.Length)
        {
            var current = s[r] - 'a';
            ++currentFrequencies[current];

            while (currentFrequencies[current] > frequencies[current])
            {
                --currentFrequencies[s[l] - 'a'];
                ++l;
            }

            if (frequencies.SequenceEqual(currentFrequencies))
            {
                result.Add(l);
            }

            ++r;
        }

        return result;
    }
}