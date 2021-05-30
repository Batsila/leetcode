public class Solution 
{
    public int ClimbStairs(int n) 
    {       
        var pr1 = 1;
        var pr2 = 1;
        
        for (int i = 2; i <= n; ++i)
        {
            int cur = pr1 + pr2;
            pr1 = pr2;
            pr2 = cur;
        }
        
        return pr2;
    }
}