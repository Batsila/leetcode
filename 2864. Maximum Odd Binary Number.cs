public class Solution
{
    public string MaximumOddBinaryNumber(string s)
    {
        var zerosCount = s.Where(c => c == '0').Count();
        var ans = new char[s.Length];
        var ind = s.Length - 1;
        ans[ind] = '1';

        while (ind > 0)
        {
            --ind;
            if (zerosCount > 0)
            {
                ans[ind] = '0';
                --zerosCount;
            }
            else
            {
                ans[ind] = '1';
            }
        }

        return new string(ans);
    }
}