class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        vector<bool> visited(rooms.size(), false);

        dfs(0, rooms, visited);
        
        for (int i = 0; i < rooms.size(); ++i)
        {
            if (not visited[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    void dfs(int v, vector<vector<int>>& graph, vector<bool>& visited)
    {
        visited[v] = true;
        
        for (int u : graph[v])
        {
            if (not visited[u])
            {
                dfs(u, graph, visited);
            }   
        }
    }
};