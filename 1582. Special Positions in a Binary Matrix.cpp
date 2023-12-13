class Solution 
{
public:
    int numSpecial(vector<vector<int>>& mat) 
    {
        vector<int> row_sum = vector<int>(mat.size());
        vector<int> col_sum = vector<int>(mat[0].size());
        
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[i].size(); ++j)
            {
                row_sum[i] += mat[i][j];
                col_sum[j] += mat[i][j];
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[i].size(); ++j)
            {
                if (row_sum[i] == 1 && col_sum[j] == 1 && mat[i][j] == 1)
                {
                    ++ans;
                }
            }
        }
            
        return ans;
    }
};