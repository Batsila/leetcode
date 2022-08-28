class Solution
{
    map<int, priority_queue<int, vector<int>, greater<int>>> m;
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
    {
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[i].size(); ++j)
            {
                m[i - j].push(mat[i][j]);
            }
        }
        
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[i].size(); ++j)
            {
                mat[i][j] = m[i - j].top();
                m[i - j].pop();
            }
        }
        
        return mat;
    }
};