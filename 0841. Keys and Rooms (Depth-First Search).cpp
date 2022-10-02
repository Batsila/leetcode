class Solution
{
    bool used[1000];

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {   
        dfs(0, rooms);
        
        for (int i = 0; i < rooms.size(); ++i)
        {
            if (!used[i])
            {
                return false;
            }
        }
        
        return true;
        
    }
    
    void dfs(int v, vector<vector<int>>& g)
    {
        used[v] = 1;
        
        for (int u : g[v])
        {
            if (!used[u])
            {
                dfs(u, g);
            }   
        }
    }
};