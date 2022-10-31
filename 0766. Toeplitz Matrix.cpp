class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        map<int, int> m;
        
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (m.find(i - j) != m.end() and m[i - j] != matrix[i][j])
                {
                    return false;
                }
                else
                {
                    m[i - j] = matrix[i][j];
                }
            }
        }
        
        return true;
    }
};