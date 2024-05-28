public class Solution
{
    public int EqualSubstring(string s, string t, int maxCost)
    {
        var l = 0;
        var r = 0;
        var cost = 0;
        var result = 0;

        while (r < s.Length)
        {
            cost += Math.Abs(s[r] - t[r]);
            ++r;

            while (cost > maxCost)
            {
                cost -= Math.Abs(s[l] - t[l]);;
                ++l;
            }

            result = Math.Max(result, r - l);
        }

        return result;
    }
}