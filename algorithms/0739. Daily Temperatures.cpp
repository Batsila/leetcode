class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> ans;
        
        vector<int> temp_ind(71, -1);
        
        for (int i = temperatures.size() - 1; i >= 0; --i)
        {
            int ct = temperatures[i];
            
            int next = INT_MAX;
            
            for (int j = ct + 1; j <= 100; ++j)
            {
                if (temp_ind[j - 30] != -1)
                {
                    next = min(next, temp_ind[j - 30] - i);
                }
            }
            
            ans.push_back(next == INT_MAX ? 0 : next);
            temp_ind[ct - 30] = i;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};