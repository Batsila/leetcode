public class Solution
{
    public string ReplaceWords(IList<string> dictionary, string sentence)
    {
        var roots = new HashSet<string>(dictionary);
        var words = sentence.Split();
        var newWords = words.Select(word => GetRoot(word, roots));

        return string.Join(" ", newWords);
    }

    private string GetRoot(string word, HashSet<string> roots)
    {
        for (int i = 0; i < word.Length; ++i)
        {
            if (roots.Contains(word[0..i]))
            {
                return word[0..i];
            }
        }

        return word;
    }
}