public class Solution
{
    public bool IsAnagram(string s, string t)
    {
        if (s.Length != t.Length)
        {
            return false;
        }

        s = String.Concat(s.OrderBy(c => c));
        t = String.Concat(t.OrderBy(c => c));

        for (var i = 0; i < s.Length; ++i)
        {
            if (s[i] != t[i])
            {
                return false;
            }
        }

        return true;
    }
}