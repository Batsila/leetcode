class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int xr = x ^ y;
        
        int ans = 0;
        
        for (int i = 0; i < 32; ++i)
        {
            if (xr >> i & 1)
            {
                ++ans;
            }
        }
        
        return ans;
    }
};