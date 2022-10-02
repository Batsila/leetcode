class Solution
{
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        
        while (l < r)
        {
            int m = (l + r) / 2;
            int tt = 0;
            
            for (int pile : piles)
            {
                int ct = pile / m;
                
                if (pile % m)
                {
                    ++ct;
                }
                
                tt += ct;
            }
            
            if (tt <= h)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        
        return r;
    }
};