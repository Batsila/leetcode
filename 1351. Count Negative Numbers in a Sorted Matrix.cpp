class Solution
{
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int ans = 0;
        
        for (vector<int>& row : grid)
        {
            int ind = upper_bound(row.begin(), row.end(), 0, greater<int>()) - row.begin();
            ans += (row.size() - ind);
        }
        
        return ans;
    }
};