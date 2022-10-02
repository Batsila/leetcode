class Solution
{
public:
    int minCostToMoveChips(vector<int>& positions)
    {
        int even = 0;
        int odd = 0;
        
        for (int position : positions)
        {
            if (position % 2)
            {
                ++odd;
            }
            else
            {
                ++even;
            }
        }
        
        return min(odd, even);
    }
};