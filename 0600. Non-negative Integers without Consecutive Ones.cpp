class Solution
{
public:
    int findIntegers(int n)
    {
        vector<int> f(32);
        f[0] = 1;
        f[1] = 2;
        
        for (int i = 2; i < f.size(); ++i)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        
        int ans = 1;
        int p = 0;
        
        for (int i = 30; i >= 0; --i)
        {
            if ((n & (1 << i)) != 0)
            {
                ans += f[i];
                
                if (p)
                {
                    --ans;
                    break;
                }
                
                p = 1;
            }
            else
            {
                p = 0;
            }
        }
        
        return ans;
    }
};