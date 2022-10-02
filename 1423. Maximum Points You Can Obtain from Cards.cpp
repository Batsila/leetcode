class Solution 
{
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int n = cardPoints.size() - k;
        
        int l = 0;
        int r = n - 1;
        
        int s = 0;
        int cs = 0;
        
        for (int i = 0; i < cardPoints.size(); ++i)
        {
            s += cardPoints[i];
            
            if (i < n)
            {
                cs += cardPoints[i];
            }
        }
        
        int ans = s - cs;
        
        while (r < cardPoints.size() - 1)
        {
            cs += cardPoints[++r];
            cs -= cardPoints[l++];
            
            ans = max(ans, s - cs);
        }
        
        return ans;
    }
};