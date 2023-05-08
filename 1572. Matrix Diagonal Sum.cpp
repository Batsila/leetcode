class Solution 
{
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int sum = 0;
        
        for (int i = 0; i < mat.size(); ++i)
        {
            sum += mat[i][i];
            sum += mat[mat.size() - 1 - i][i];
        }
        
        if (mat.size() % 2 == 1)
        {
           sum -= mat[mat.size() / 2][mat.size() / 2];
        }
        
        return sum;
    }
};