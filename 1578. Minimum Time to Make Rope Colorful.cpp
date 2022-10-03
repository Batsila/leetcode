class Solution
{
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int ans = 0;
        int cm = 0;
        
        for (int i = 0; i < colors.size(); ++i)
        {
            if (i > 0 and colors[i] != colors[i - 1])
            {
                cm = 0;
            }
            
            ans += min(cm, neededTime[i]);
            cm = max(cm, neededTime[i]);
        }
        
        return ans;
    }
};