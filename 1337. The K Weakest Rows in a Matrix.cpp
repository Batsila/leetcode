class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 1; j < mat[i].size(); ++j)
            {
                mat[i][0] += mat[i][j];
            }
        }
        
        vector<vector<int>> res;
        
        for (int i = 0; i < mat.size(); ++i)
        {
            res.push_back({mat[i][0], i});
        }
        
        sort(res.begin(), res.end());
        
        vector<int> ans;
        
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(res[i][1]);
        }
        
        return ans;
    }
};