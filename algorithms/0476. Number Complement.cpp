class Solution
{
public:
    int findComplement(int num)
    {
        if (num == 0)
        {
            return 1;
        }
        
        bool lz = true;
        
        for (int i = 31; i >= 0; --i)
        {
            if (lz and num >> i & 1)
            {
                lz = false;
            }
            
            if (not lz)
            {
                num ^= 1 << i;
            }
        }
        
        return num;
    }
};