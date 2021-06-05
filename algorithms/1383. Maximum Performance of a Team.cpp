class Solution
{
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k)
    {
        vector<pair<int, int>> v;
        
        for (int i = 0; i < n; ++i)
        {
            v.push_back(make_pair(efficiency[i], speed[i]));
        }
        
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)
             {
                return a.first > b.first;
             });
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        long ans = 0;
        long sum = 0;
        
        for (auto p : v)
        {
            if (pq.size() >= k)
            {
                sum -= pq.top();
                pq.pop();
            }
            
            pq.push(p.second);
            
            sum += p.second;
            
            ans = max(ans, sum * p.first);
        }
        
        return ans % 1000000007;
    }
};