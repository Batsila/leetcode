class Solution 
{
public:
    int minSetSize(vector<int>& arr) 
    {
        unordered_map<int, int> m;
        
        for (int a : arr)
        {   
            ++m[a];
        }
        
        priority_queue<int> pq;
        
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            pq.push(it->second);
        }
        
        int csum = 0;
        int c = 0;
        
        while (csum < arr.size() / 2)
        {
            csum += pq.top();
            pq.pop();
            ++c;
        }
        
        return c;
    }
};