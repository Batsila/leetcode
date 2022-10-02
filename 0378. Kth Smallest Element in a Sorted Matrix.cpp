class Solution
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        priority_queue<int, vector<int>, less<int>> pq;
        
        for (int i = 0; i < n * n; ++i)
        {
            int element = matrix[i / n][i % n];
            
            if (pq.size() < k)
            {
                pq.push(element);
            }
            else
            {
                if (element <= pq.top())
                {
                    pq.push(element);
                    pq.pop();
                }
            }
        }
        
        return pq.top();
    }
};