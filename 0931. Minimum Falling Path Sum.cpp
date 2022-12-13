class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        vector<vector<int>> dp(
            matrix.size(),
            vector<int>(matrix[0].size(), INT_MAX));

        for (int i = 0; i < matrix[0].size(); ++i)
        {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                for (int k = -1; k <= 1; ++k)
                {
                    if (j + k >= 0 and j + k < matrix[i - 1].size())
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j + k] + matrix[i][j]);
                    }
                }
            }
        }

        return *min_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());
    }
};