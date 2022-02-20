class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        
        int l = intervals[0][0];
        int r = intervals[0][1];
        
        int ans = 1;
        
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] > l and intervals[i][1] > r)
            {
                ++ans;
            }
            
            if (intervals[i][1] > r)
            {
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        
        return ans;
    }
};