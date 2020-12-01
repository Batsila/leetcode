public class Solution 
{
    public int GetLastMoment(int n, int[] left, int[] right) 
    {        
        if (left.Any() && right.Any())
        {
            return Math.Max(left.Max(), n - right.Min());
        }
        
        if (left.Any())
        {
            return left.Max();
        }
        
        if (right.Any())
        {
            return n - right.Min();
        }
        
        return 0;
    }
}