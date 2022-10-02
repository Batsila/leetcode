class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        if (k == nums.size())
        {
            return nums;
        }
        
        unordered_map<int, int> m;
        
        for (int num : nums)
        {
            ++m[num];
        }
        
        auto comp = [&m](int n1, int n2)
        {
            return m[n1] > m[n2];
        };
        
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        
        for (auto p : m)
        {
            pq.push(p.first);
            
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        
        vector<int> ans;
        
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};