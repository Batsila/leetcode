class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
    {
        vector<vector<int>> ps(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (i == 0 and j == 0)
                {
                    ps[i][j] = matrix[i][j];
                }
                else if (i == 0)
                {
                    ps[i][j] = ps[i][j - 1] + matrix[i][j];
                }
                else if (j == 0)
                {
                    ps[i][j] = ps[i - 1][j] + matrix[i][j];
                }
                else
                {
                    ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + matrix[i][j];
                }
            }
        }
        
        int ans = INT_MIN;
        
        for (int i1 = 0; i1 < matrix.size(); ++i1)
        {
            for (int j1 = 0; j1 < matrix[0].size(); ++j1)
            {
                for (int i2 = i1; i2 < matrix.size(); ++i2)
                {
                    for (int j2 = j1; j2 < matrix[0]. size(); ++j2)
                    {
                        int sum = INT_MIN;
                        
                        if (i1 == 0 and j1 == 0)
                        {
                            sum = ps[i2][j2];
                        }
                        else if (i1 == 0)
                        {
                            sum = ps[i2][j2] - ps[i2][j1 - 1];
                        }
                        else if (j1 == 0)
                        {
                            sum = ps[i2][j2] - ps[i1 - 1][j2];
                        }
                        else
                        {
                            sum = ps[i2][j2] - ps[i2][j1 - 1] - ps[i1 - 1][j2] + ps[i1 - 1][j1 - 1];
                        }
                        
                        if (sum <= k)
                        {
                            ans = max(ans, sum);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};