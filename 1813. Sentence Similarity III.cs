public class Solution
{
    public bool AreSentencesSimilar(string sentence1, string sentence2)
    {
        var words1 = sentence1.Split().ToArray();
        var words2 = sentence2.Split().ToArray();

        var l = 0;
        var r = 0;

        while ((l + r) < words1.Length
            && (l + r) < words2.Length
            && words1[l] == words2[l])
        {
            ++l;
        }

        while ((l + r) < words1.Length
            && (l + r) < words2.Length
            && words1[^(r + 1)] == words2[^(r + 1)])
        {
            ++r;
        }

        return l + r == words1.Length || l + r == words2.Length;
    }
}