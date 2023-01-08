class Solution
{
public:
    int maxPoints(vector<vector<int>>& points)
    {
        if (points.size() == 1)
        {
            return 1;
        }

        int ans = 2;

        for (int i = 0; i < points.size(); ++i)
        {
            map<double, int> m;

            for (int j = 0; j < points.size(); ++j)
            {
                if (i != j)
                {
                    double angle = atan2(points[j][1] - points[i][1], points[j][0] - points[i][0]);
                    ++m[angle];
                }
            }

            for (auto p : m)
            {
                ans = max(ans, p.second + 1);
            }
        }

        return ans;
    }
};