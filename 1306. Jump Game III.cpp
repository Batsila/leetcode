class Solution 
{
    bool reached = false;
    vector<vector<int>> g;
    vector<bool> is_visited;
    
public:
    bool canReach(vector<int>& arr, int start) 
    {
        
        for (int i = 0; i < arr.size(); ++i)
        {  
            vector<int> v;
            g.push_back(v);
            is_visited.push_back(false);
        }
        
        
        for (int i = 0; i < arr.size(); ++i)
        {
            int l = i - arr[i];
            int r = i + arr[i];
            
            if (l >= 0 && l < arr.size() && l != i)
            {
                g[i].push_back(l);
            }
            
            if (r >= 0 && r < arr.size() && r != i)
            {
                g[i].push_back(r);
            }
        }
        
        dfs(start, arr);
        
        return reached;
    }
    
    void dfs(int v, vector<int>& arr)
    {
        is_visited[v] = true;
        
        if (!arr[v])
        {
            reached = true;
            return;
        }
        
        for (int u : g[v])
        {
            if (!is_visited[u])
            {
                dfs(u, arr);
            }
        }

    }
};