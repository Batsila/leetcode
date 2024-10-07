public class Solution
{
    public int MinLength(string s)
    {
        while (s.Contains("AB") || s.Contains("CD"))
        {
            s = s.Replace("AB", "");
            s = s.Replace("CD", "");
        }

        return s.Length;
    }
}