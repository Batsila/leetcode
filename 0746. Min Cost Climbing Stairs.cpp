class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int f = cost[0];
        int s = cost[1];
        
        for (int i = 2; i < cost.size(); ++i)
        {
            int n = min(f, s) + cost[i];
            
            f = s;
            s = n;
        }
        
        return min(f, s);
    }
};