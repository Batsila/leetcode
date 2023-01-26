class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; ++i)
        {
            vector<int> temp(dist);

            for (auto flight : flights)
            {
                if (dist[flight[0]] != INT_MAX)
                {
                    temp[flight[1]] = min(temp[flight[1]], dist[flight[0]] + flight[2]);
                }
            }

            dist = temp;
        }

        if (dist[dst] != INT_MAX)
        {
            return dist[dst];
        }

        return -1;
    }
};