class StockSpanner
{
    stack<vector<int>> s;
public:
    int next(int price)
    {
        int ans = 1;
        
        while (not s.empty() and s.top()[0] <= price)
        {
            ans += s.top()[1];
            s.pop();
        }
        
        s.push({price, ans});
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */