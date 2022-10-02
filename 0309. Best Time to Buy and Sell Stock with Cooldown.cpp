class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int sell = 0;
        int buy = INT_MIN;
        int prev_sell = 0;
        int prev_buy = INT_MIN;
        
        for (int price : prices)
        {
            prev_buy = buy;
            buy = max(buy, prev_sell - price);
            prev_sell = sell;
            sell = max(sell, prev_buy + price);
        }
        
        return sell;
    }
};