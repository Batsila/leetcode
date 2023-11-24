class Solution 
{
public:
    int maxCoins(vector<int>& piles) 
    {
        sort(piles.begin(), piles.end());
        reverse(piles.begin(), piles.end());
        
        int ans = 0;
        
        for (int i = 0; i < piles.size() / 3; ++i)
        {
            ans += piles[2 * i + 1];
        }
        
        return ans;
    }
};