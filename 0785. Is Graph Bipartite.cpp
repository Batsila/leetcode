class Solution
{
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        vector<int> color(graph.size(), 0);
        
        for (int i = 0; i < graph.size(); ++i)
        {
            if (not color[i])
            {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                
                while (not q.empty())
                {
                    int parent = q.front();
                    q.pop();
                    
                    for (int chiled : graph[parent])
                    {
                        if (not color[chiled])
                        {
                            color[chiled] = -color[parent];
                            q.push(chiled);
                        }
                        else
                        {
                            if (color[chiled] == color[parent])
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        
        return true;
    }
};