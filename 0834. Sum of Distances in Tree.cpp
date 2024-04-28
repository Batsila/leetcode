class Solution
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(n, vector<int>());
        
        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> nodesInSubTree(n, 1);
        vector<int> ans(n, 0);
        
        calculateSubTreesSum(0, -1, graph, nodesInSubTree, ans);
        addBackwardPathSum(0, -1, graph, nodesInSubTree, ans);
        
        return ans;
    }
    
    void calculateSubTreesSum(
        int currentNode,
        int previousNode,
        vector<vector<int>>& graph,
        vector<int>& nodesInSubTree,
        vector<int>& ans)
    {
        for (int adjacentNode : graph[currentNode])
        {
            if (adjacentNode != previousNode)
            {
                calculateSubTreesSum(adjacentNode, currentNode, graph, nodesInSubTree, ans);
                nodesInSubTree[currentNode] += nodesInSubTree[adjacentNode];
                ans[currentNode] += ans[adjacentNode] + nodesInSubTree[adjacentNode];
            }
        }
    }
    
    void addBackwardPathSum(
        int currentNode,
        int previousNode,
        vector<vector<int>>& graph,
        vector<int>& nodesInSubTree,
        vector<int>& ans)
    {
        for (int adjacentNode : graph[currentNode])
        {
            if (adjacentNode != previousNode)
            {
                ans[adjacentNode] = ans[currentNode] - nodesInSubTree[adjacentNode] + (graph.size() - nodesInSubTree[adjacentNode]);
                addBackwardPathSum(adjacentNode, currentNode, graph, nodesInSubTree, ans);
            }
        }
    }
};