class Solution
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        map<int, int> balances;
        
        for (auto trip : trips)
        {
            balances[trip[1]] += trip[0];
            balances[trip[2]] -= trip[0];
        }
        
        int current = 0;
        
        for (auto balance : balances)
        {
            current += balance.second;
            
            if (current > capacity)
            {
                return false;
            }
        }
        
        return true;
    }
};