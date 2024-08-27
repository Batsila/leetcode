class Solution
{
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<double> max_prob(n, 0);
        max_prob[start] = 1;
        
        for (int i = 0; i < n - 1; ++i)
        {
            bool is_updated = false;

            for (int j = 0; j < edges.size(); ++j)
            {
                int u = edges[j][0];
                int v = edges[j][1];

                if (max_prob[u] * succProb[j] > max_prob[v])
                {
                    max_prob[v] = max_prob[u] * succProb[j];
                    is_updated = true;
                }
                else if (max_prob[v] * succProb[j] > max_prob[u])
                {
                    max_prob[u] = max_prob[v] * succProb[j];
                    is_updated = true;
                }
            }

            if (!is_updated)
            {
                break;
            }
        }
        
        return max_prob[end];
    }
};