class Solution
{
public:
    int nthMagicalNumber(int n, int a, int b)
    {
        int lcm = a * b / gcd(a, b);
        
        long l = 0;
        long r = (long)n * min(a, b);
        
        while (l < r)
        {
            long m = (l + r) / 2;
            
            if (m / a + m / b - m / lcm < n)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        
        return l % 1000000007;
    }
    
    int gcd(int x, int y)
    {
        if (not x)
        {
            return y;
        }
        
        return gcd(y % x, x);
    }
};