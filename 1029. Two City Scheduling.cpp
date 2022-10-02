class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        vector<int> d;
        
        int ans = 0;
        
        for (auto cost : costs)
        {
            ans += cost[0];
            d.push_back(cost[1] - cost[0]);
        }
        
        sort(d.begin(), d.end());
        
        for (int i = 0; i < costs.size() / 2; ++i)
        {
            ans += d[i];
        }
        
        return ans; 
    }
};