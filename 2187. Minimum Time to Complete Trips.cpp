class Solution
{
public:
    long long minimumTime(vector<int>& times, int totalTrips)
    {
        long long l = 0;
        long long r = 100000000000001;

        while (l <= r)
        {
            long long trips = 0;
            long long m = (l + r) / 2;
            
            for (int time : times)
            {
                trips += m / time;
            }

            if (trips < totalTrips)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return l;
    }
};