class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end());
        
        int r = points[0][1];
        int ans = 1;
        
        for (int i = 1; i < points.size(); ++i)
        {
            if (r < points[i][0])
            {
                ++ans;
                r = points[i][1];
            }
            else
            {
                r = min(r, points[i][1]);
            }
        }
        
        return ans;
    }
};