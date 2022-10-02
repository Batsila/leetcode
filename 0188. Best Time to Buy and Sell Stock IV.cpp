class Solution
{
public:
    int maxProfit(int k, vector<int>& prices)
    {
        if (k == 0)
        {
            return 0;
        }
        
        vector<int> minCost(k + 1, INT_MAX);
        vector<int> maxProfit(k + 1);
        
        for (int price : prices)
        {
            for (int i = 1; i <= k; ++i)
            {
                minCost[i] = min(minCost[i], price - maxProfit[i - 1]);
                maxProfit[i] = max(maxProfit[i], price - minCost[i]);
            }
        }
        
        return maxProfit[k];
    }
};