public class Solution
{
    public IList<string> WordBreak(string s, IList<string> wordDict)
    {
        var result = new List<string>();

        Backtrack(s, 0, wordDict, [], result);

        return result;
    }

    private void Backtrack(
        string s,
        int position,
        IList<string> wordDict,
        List<string> current,
        List<string> result)
    {
        if (position < s.Length)
        {
            foreach (var word in wordDict)
            {
                if (IsWordApplicable(s, position, word))
                {
                    current.Add(word);
                    Backtrack(s, position + word.Length, wordDict, current, result);
                    current.RemoveAt(current.Count - 1);
                }
            }
        }
        else
        {
            result.Add(string.Join(" ", current));
        }
    }

    private bool IsWordApplicable(string s, int position, string word)
    {
        if (s.Length - position >= word.Length)
        {
            for (int i = 0; i < word.Length; ++i)
            {
                if (s[position + i] != word[i])
                {
                    return false;
                }
            }

            return true;
        }
        else
        {
            return false;
        }
    }
}