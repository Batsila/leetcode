class Solution
{
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        vector<int> limits(n);
        int left_limit = 0;

        for (int i = 0; i < n; ++i)
        {
            limits[i] = left_limit;
            left_limit = max(left_limit, height[i]);
        }

        int right_limit = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            limits[i] = min(right_limit, limits[i]);
            right_limit = max(right_limit, height[i]);
        }

        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            int capacity = limits[i] - height[i];

            if (capacity > 0)
            {
                ans += capacity;
            }
        }

        return ans;
    }
};