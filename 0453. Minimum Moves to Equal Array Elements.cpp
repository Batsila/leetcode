class Solution
{
public:
    int minMoves(vector<int>& nums)
    {
        int mn = INT_MAX;
        
        for (int n : nums)
        {
            mn = min(mn, n);
        }
        
        int ans = 0;
        
        for (int n : nums)
        {
            ans += n - mn;
        }
        
        return ans;
    }
};