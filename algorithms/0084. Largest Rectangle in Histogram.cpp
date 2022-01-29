class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int ans = INT_MIN;
        int ind = 0;
        stack<int> s;
        
        while (ind < heights.size())
        {
            if (s.empty() or heights[s.top()] <= heights[ind])
            {
                s.push(ind);
                ++ind;
            }
            else
            {
                int t = s.top();
                s.pop();
                int c = s.empty() ? ind : ind - s.top() - 1;
                ans = max(ans, heights[t] * c);
            }
        }
        
        while (not s.empty())
        {
            int t = s.top();
            s.pop();
            int c = s.empty() ? ind : ind - s.top() - 1;
            ans = max(ans, heights[t] * c);
        }
        
        return ans;
    }
};