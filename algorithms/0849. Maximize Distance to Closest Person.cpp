class Solution
{
public:
    int maxDistToClosest(vector<int>& seats)
    {
        int ans = 1;
        int d = 0;
        
        for (int seat : seats)
        {
            if (seat)
            {
                d = 0;
            }
            else
            {
                ++d;
                ans = max(ans, (d + 1) / 2);
            }
        }
        
        for (int i = 0; i < seats.size(); ++i)
        {
            if (seats[i])
            {
                ans = max(ans, i);
                break;
            }
        }
        
        for (int i = seats.size() - 1; i >= 0; --i)
        {
            if (seats[i])
            {
                ans = max(ans, (int)seats.size() - 1 - i);
                break;
            }
        }
        
        return ans;
    }
};