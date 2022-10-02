class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int ans = 0;
        int t = 0;
        int c = 0;
        
        for (int i = 0; i < gas.size(); ++i)
        {
            int d = gas[i] - cost[i];
            t += d;
            c += d;
            
            if (c < 0)
            {
                c = 0;
                ans = i + 1 % gas.size();
            }
        }
        
        return t < 0 ? -1 : ans;
    }
};