class Solution 
{
public:
    int fib(int n) 
    {
        if (!n)
        {
            return 0;
        }
        
        if (n < 2)
        {
            return 1;
        }
        
        int a = 1;
        int b = 1;
        
        for (int i = 2; i < n; ++i)
        {
            int t = b;
            b += a;
            a = t;
        }
        
        return b;
    }
};