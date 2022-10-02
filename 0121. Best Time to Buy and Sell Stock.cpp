class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int ans = 0;
        
        if (prices.size() > 1)
        {
            int min_p = prices[0];
            
            for (int i = 1; i < prices.size(); ++i)
            {
                ans = max(ans, prices[i] - min_p);
                min_p = min(min_p, prices[i]);
            }
        }
        
        return ans;
    }
};