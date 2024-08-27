class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<vector<pair<int, double>>> graph(n, vector<pair<int, double>>());
        
        for (int i = 0; i < edges.size(); ++i)
        {
            graph[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            graph[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }

        double* max_prob = new double[n];
        max_prob[start] = 1;
        priority_queue<pair<double, int>> heap;
        heap.push(make_pair(1.0, start));
        
        while (!heap.empty())
        {
            auto current_node = heap.top();
            heap.pop();

            if (current_node.second == end)
            {
                return current_node.first;
            }
            else
            {
                for (auto node : graph[current_node.second])
                {
                    if (current_node.first * node.second > max_prob[node.first])
                    {
                        max_prob[node.first] = current_node.first * node.second;
                        heap.push(make_pair(max_prob[node.first], node.first));
                    }
                }
            } 
        }
        
        return 0;
    }
};