public class Solution
{
    public int GetLucky(string s, int k)
    {
        var source = string.Join("", s.Select(c => (c - 'a' + 1).ToString()));

        while (k > 0)
        {
            var num = source.Select(x => x - '0').Sum();
            source = num.ToString();
            --k;
        }

        return int.Parse(source);
    }
}