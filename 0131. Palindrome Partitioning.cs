public class Solution
{
    public IList<IList<string>> Partition(string s)
    {
        var result = new List<IList<string>>();
        Backtrack(s, 0, new List<string>(), result);

        return result;
    }

    private void Backtrack(string s, int start, List<string> currentPartitioning , IList<IList<string>> result)
    {
        if (start == s.Length)
        {
            result.Add(new List<string>(currentPartitioning));
        }
        else
        {
            for (var end = start + 1; end < s.Length + 1; ++end)
            {
                var substring = s[start..end];

                if (IsPalindrome(substring))
                {
                    currentPartitioning.Add(substring);
                    Backtrack(s, end, currentPartitioning, result);
                    currentPartitioning.RemoveAt(currentPartitioning.Count - 1);
                }
            }
        }
    }

    private bool IsPalindrome(string s)
    {
        return s.SequenceEqual(s.Reverse());
    }
}