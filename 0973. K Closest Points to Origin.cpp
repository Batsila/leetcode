class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        priority_queue<vector<int>> pq;
        
        for (auto point : points)
        {
            int d = point[0] * point[0] + point[1] * point[1];
            pq.push({ d, point[0], point[1] });
            
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        
        vector<vector<int>> ans;
        
        while (pq.size())
        {
            auto p = pq.top();
            ans.push_back({ p[1], p[2] });
            pq.pop();
        }
        
        return ans;
    }
};