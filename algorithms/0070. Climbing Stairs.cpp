class Solution
{
public:
    int climbStairs(int n)
    {
        int pr1 = 1;
        int pr2 = 1;
        
        for (int i = 2; i <= n; ++i)
        {
            int cur = pr1 + pr2;
            pr1 = pr2;
            pr2 = cur;
        }
        
        return pr2;
    }
};