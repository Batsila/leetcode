class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n));
        
        int l = 0;
        int r = n - 1;
        int u = 0;
        int d = n - 1;
        int ind = 1;
        
        while (true)
        {
            for (int i = l; i <= r; ++i)
            {
                ans[u][i] = ind++;
            }
            
            if (ind > n * n)
            {
                break;
            }
            
            for (int i = u + 1; i <= d; ++i)
            {
                ans[i][r] = ind++;
            }
            
            if (ind > n * n)
            {
                break;
            }
            
            for (int i = r - 1; i >= l; --i)
            {
                ans[d][i] = ind++;
            }
            
            if (ind > n * n)
            {
                break;
            }
            
            for (int i = d - 1; i > u; --i)
            {
                ans[i][l] = ind++;
            }
            
            if (ind > n * n)
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