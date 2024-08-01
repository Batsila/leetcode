public class Solution
{
    public int CountSeniors(string[] details)
    {
        return details.Where(x => x[11] > '6' || (x[11] == '6' && x[12] > '0')).Count();
    }
}