class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        long xr = 0;
        
        for (int num : nums)
        {
            xr ^= num;
        }
        
        int mask = xr & (-xr);
        
        int a = 0;
        int b = 0;
        
        for (int num : nums)
        {
            if (num & mask)
            {
                a ^= num;
            }
            else
            {
                b ^= num;
            }
        }
        
        return { a, b };
    }
};