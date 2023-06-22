class Solution
{
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int ans = 0;
        int hold = -prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            int t = hold;
            hold = max(hold, ans - prices[i]);
            ans = max(ans, t + prices[i] - fee);
        }

        return ans;
    }
};