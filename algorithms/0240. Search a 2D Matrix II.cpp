class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int i = matrix.size() - 1;
        int j = 0;
        
        while (i >= 0 and j < matrix[0].size())
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            
            if (matrix[i][j] < target)
            {
                ++j;
            }
            else
            {
                --i;
            }
        }
        
        return false;
    }
};