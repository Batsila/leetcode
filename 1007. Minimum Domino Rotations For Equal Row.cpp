class Solution
{
    int t[7];
    int b[7];
    int s[7];
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        for (int i = 0; i < tops.size(); ++i)
        {
            ++t[tops[i]];
            ++b[bottoms[i]];
            
            if (tops[i] == bottoms[i])
            {
                ++s[tops[i]];
            }
        }
        
        int ans = INT_MAX;
        
        for (int i = 1; i <= 6; ++i)
        {
            if (t[i] + b[i] - s[i] == tops.size())
            {
                ans = min(ans, min(t[i], b[i]) - s[i]);
            }
        }
        
        if (ans == INT_MAX)
        {
            return -1;
        }
        
        return ans;
    }
};