class Solution
{
public:
    int trap(vector<int>& height)
    {
        if (height.size() == 0)
        {
            return 0;
        }
        
        vector<int> l(height.size(), 0);
        int ml = height[0];
        
        for (int i = 1; i < height.size(); ++i)
        {
            if (height[i] >= ml)
            {
                ml = height[i];
            }
            else
            {
                l[i] = ml - height[i];
            }
        }
        
        vector<int> r(height.size(), 0);
        int mr = height[height.size() - 1];
        
        for (int i = height.size() - 2; i >= 0; --i)
        {
            if (height[i] >= mr)
            {
                mr = height[i];
            }
            else
            {
                r[i] = mr - height[i];
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < l.size(); ++i)
        {
            ans += min(l[i], r[i]);
        }
        
        return ans;
    }
};