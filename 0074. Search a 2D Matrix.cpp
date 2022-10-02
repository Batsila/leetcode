class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int l = 0;
        int r = matrix.size() * matrix[0].size() - 1;
        
        while (l <= r)
        {
            int m = (l + r) / 2;
            int i = m / matrix[0].size();
            int j = m % matrix[0].size();
            
            if (matrix[i][j] == target)
            {
                return true;
            }
            
            if (target < matrix[i][j])
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        
        return false;
    }
};