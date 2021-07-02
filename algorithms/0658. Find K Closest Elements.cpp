class Solution
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        auto cmp = [x](const int a, const int b)
        {
            int da = abs(a - x);
            int db = abs(b - x);
            
            if (da == db)
            {
                return a < b;
            }
            else
            {
                return da < db;
            }
        };
        
        priority_queue<int, vector<int>, function<bool(int, int)>> pq(cmp);
        
        for (int item : arr)
        {
            pq.push(item);
            
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        
        vector<int> ans;
        
        while (not pq.empty())
        {
            ans.push_back(pq.top());
            
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};