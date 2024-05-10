class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    {
        priority_queue<pair<double, pair<int,int>>> pq;

        for (int i = 0; i < arr.size() - 1; ++i)
        {
            pq.push(
                {
                    -1.0 * arr[i] / arr[arr.size() - 1],
                    { i, arr.size() - 1 }
                });
        }

        while (k > 1)
        {
            --k;
            auto current = pq.top().second;
            pq.pop();
            pq.push(
                {
                    -1.0 * arr[current.first] / arr[current.second - 1],
                    { current.first, current.second - 1 }
                });
        }
        
        auto ans = pq.top().second;

        return { arr[ans.first], arr[ans.second] };
    }
};