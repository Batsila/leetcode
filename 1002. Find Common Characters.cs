public class Solution
{
    public IList<string> CommonChars(string[] words)
    {
        int[] lettersFrequencies = null;

        foreach (var word in words)
        {
            var currentFrequencies = CountFrequencies(word);
            lettersFrequencies ??= currentFrequencies;
            lettersFrequencies = GetIntersection(lettersFrequencies, currentFrequencies);
        }

        var result = new List<string>();

        for (int i = 0; i < 26; ++i)
        {
            result.AddRange(Enumerable.Range(0, lettersFrequencies[i]).Select(x => $"{(char)('a' + i)}"));
        }

        return result;
    }

    private int[] CountFrequencies(string word)
    {
        var frequencies = new int[26];

        foreach (var c in word)
        {
            ++frequencies[c - 'a'];
        }

        return frequencies;
    }

    private int[] GetIntersection(int[] a, int[] b)
    {
        var intersection = new int[26];

        for (int i = 0; i < intersection.Length; ++i)
        {
            intersection[i] = Math.Min(a[i], b[i]);
        }

        return intersection;
    }
}