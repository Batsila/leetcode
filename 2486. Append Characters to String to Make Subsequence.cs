public class Solution
{
    public int AppendCharacters(string s, string t)
    {
        var sInd = 0;
        var tInd = 0;

        while (sInd < s.Length && tInd < t.Length)
        {
            if (s[sInd] == t[tInd])
            {
                ++tInd;
            }

            ++sInd;
        }

        return t.Length - tInd;
    }
}