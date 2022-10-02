class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> ans;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int l = 0;
        int r = m - 1;
        int u = 0;
        int d = n - 1;
        
        while (true)
        {
            for (int i = l; i <= r; ++i)
            {
                ans.push_back(matrix[u][i]);
            }
            
            if (ans.size() == n * m)
            {
                break;
            }
            
            for (int i = u + 1; i <= d; ++i)
            {
                ans.push_back(matrix[i][r]);
            }
            
            if (ans.size() == n * m)
            {
                break;
            }
            
            for (int i = r - 1; i >= l; --i)
            {
                ans.push_back(matrix[d][i]);
            }
            
            if (ans.size() == n * m)
            {
                break;
            }
            
            for (int i = d - 1; i > u; --i)
            {
                ans.push_back(matrix[i][l]);
            }
            
            if (ans.size() == n * m)
            {
                break;
            }
            
            ++l;
            --r;
            ++u;
            --d;
        }
        
        return ans;
    }
};