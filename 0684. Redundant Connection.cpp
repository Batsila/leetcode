class Solution
{
    vector<int> p;
    vector<int> s;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        p = vector<int>(edges.size());
        
        for (int i = 0; i < edges.size(); ++i)
        {
            p[i] = i;
        }
        
        s = vector<int>(edges.size(), 1);
        
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            if (find(u - 1) == find(v - 1))
            {
                return { u, v };
            }
            else
            {
                add(u - 1, v - 1);
            }
        }
        
        return {};
    }
    
    int find(int x)
    {
        if (x != p[x])
        {
            p[x] = find(p[x]);
        }
        
        return p[x];
    }
    
    void add(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        
        p[py] = px;
        
        s[px] += s[py];
    }
};