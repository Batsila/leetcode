class Solution
{
public:
    int minJumps(vector<int>& arr)
    {
        unordered_map<int,vector<int>> g;
        
        for (int i = 0; i < arr.size(); ++i)
        {
            g[arr[i]].push_back(i);
        }
        
        vector<int> d(arr.size(), INT_MAX);
        d[0] = 0;
        
        queue<int> q;
        q.push(0);
        
        while (q.size())
        {
            int c = q.front();
            q.pop();
            
            if (c == arr.size() - 1)
            {
                return d[c];
            }
            
            vector<int> &l = g[arr[c]];
            
            if (c > 0)
            {
                l.push_back(c - 1);
            }
            
            if (c < arr.size() - 1)
            {
                l.push_back(c + 1);
            }
            
            for (int v : l)
            {
                if (d[v] > d[c] + 1)
                {
                    d[v] = d[c] + 1;
                    q.push(v);
                }
            }
            
            l.clear();
        }
        
        return -1;
    }
};