class Solution
{
public:
    int numTilings(int n)
    {
        if (n < 3)
        {
            return n;
        }
        
        vector<long> d(n + 1, 0);
        vector<long> t(n + 1, 0);
        
        d[0] = t[0] = 0;
        d[1] = t[1] = 1;
        d[2] = t[2] = 2;
        
        for (int i = 3; i <= n; ++i)
        {
            d[i] = d[i - 1] + d[i - 2] + t[i - 2] * 2;
            t[i] = t[i - 1] + d[i - 1];
            
            d[i] %= 1000000007;
            t[i] %= 1000000007;
        }
        
        return d[n];
    }
};