class Solution
{
public:
    long maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int horizontal_max = max(horizontalCuts[0], h - horizontalCuts.back());
        
        for (int i = 0; i < horizontalCuts.size() - 1; ++i)
        {
            horizontal_max = max(horizontal_max, horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        
        int vertical_max = max(verticalCuts[0], w - verticalCuts.back());
        
        for (int i = 0; i < verticalCuts.size() - 1; ++i)
        {
            vertical_max = max(vertical_max, verticalCuts[i + 1] - verticalCuts[i]);
        }
        
        return (long)horizontal_max * vertical_max % 1000000007;
    }
};