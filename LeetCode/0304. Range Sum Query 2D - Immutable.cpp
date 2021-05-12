class NumMatrix 
{
    int sum[222][222];
public:
    NumMatrix(vector<vector<int>>& matrix) 
    {
        sum[0][0] = matrix[0][0];
        
        for (int i = 1; i < matrix.size(); ++i)
        {
            sum[i][0] = matrix[i][0] + sum[i - 1][0];
        }
        
        for (int i = 1; i < matrix[0].size(); ++i)
        {
            sum[0][i] = matrix[0][i] + sum[0][i - 1];
        }
        
        for (int i = 1; i < matrix.size(); ++i)
        {
            for (int j = 1; j < matrix[0].size(); ++j)
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        if (row1 == 0 and col1 == 0)
        {
            return sum[row2][col2];
        }
        else if (row1 == 0)
        {
            return sum[row2][col2] - sum[row2][col1 - 1];
        }
        else if (col1 == 0)
        {
            return sum[row2][col2] - sum[row1 - 1][col2];
        }
        else
        {
            return sum[row2][col2] - sum[row2][col1 - 1] - sum[row1 - 1][col2] + sum[row1 - 1][col1 - 1];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */