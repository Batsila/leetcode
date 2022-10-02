class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        set<int> r;
        set<int> c;
        
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (r.find(i) != r.end() or c.find(j) != c.end())
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};