class Solution
{
    bool isComposite[5000000];
public:
    int countPrimes(int n)
    {
        for (int i = 2; i <= sqrt(n); ++i)
        {
            if (!isComposite[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    isComposite[j] = true;
                }
            }
        }
        
        int ans = 0;
        for (int i = 2; i < n; ++i)
        {
            if (!isComposite[i])
            {
                ++ans;
            }
        }
        
        return ans;
    }
};