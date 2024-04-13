class Solution
{
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int ans = 0;
        vector<int> hist(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                hist[j] = matrix[i][j] == '1' ? hist[j] + 1 : 0;
            }

            ans = max(ans, maximalHist(hist));
        }

        return ans;
    }

    int maximalHist(vector<int>& hist)
    {
        int ans = 0;

        for (int i = 0; i < hist.size(); ++i)
        {
            int l = i - 1;
            int r = i + 1;

            while (l >= 0 and hist[l] >= hist[i])
            {
                --l;
            }

            while (r < hist.size() and hist[r] >= hist[i])
            {
                ++r;
            }

            ans = max(ans, hist[i] * (r - l - 1));
        }

        return ans;
    }
};