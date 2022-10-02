class Solution
{
    long dp[555];
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        dp[0] = startFuel;
        
        for (int i = 0; i < stations.size(); ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                if (dp[j] >= stations[i][0])
                {
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }
        
        for (int i = 0; i <= stations.size(); ++i)
        {
            if (dp[i] >= target)
            {
                return i;
            }
        }
        
        return -1;
    }
};