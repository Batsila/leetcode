class Solution
{
public:
    int bitwiseComplement(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        
        bool lz = true;
        
        for (int i = 31; i >= 0; --i)
        {
            if (lz and n >> i & 1)
            {
                lz = false;
            }
            
            if (not lz)
            {
                n ^= 1 << i;
            }
        }
        
        return n;
    }
};