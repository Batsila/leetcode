class Solution
{
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k)
    {
        int n = quality.size();
        vector<pair<double, int>> coefficients;

        for (int i = 0; i < n; ++i)
        {
            coefficients.push_back({ 1.0 * wage[i] / quality[i], quality[i] });
        }

        sort(coefficients.begin(), coefficients.end());

        double ans = DBL_MAX;
        double qualities_sum = 0;
        priority_queue<int> qualities_heap;

        for (int i = 0; i < n; ++i)
        {
            qualities_heap.push(coefficients[i].second);
            qualities_sum += coefficients[i].second;

            if (qualities_heap.size() > k)
            {
                qualities_sum -= qualities_heap.top();
                qualities_heap.pop();
            }

            if (qualities_heap.size() == k)
            {
                ans = min(ans, qualities_sum * coefficients[i].first);
            }
        }

        return ans;
    }
};