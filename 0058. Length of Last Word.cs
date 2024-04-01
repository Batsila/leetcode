public class Solution
{
    public int LengthOfLastWord(string s)
    {
        return (s.Trim().Split().Last()).Length;
    }
}