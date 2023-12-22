class Solution
{
public:
    int maxScore(string s)
    {
        int n = s.size();
        vector<int> zeros(n, 0);
        vector<int> ones(n, 0);

        for (int i = 0; i < n; ++i)
        {
            zeros[i] = s[i] == '0';
            zeros[i] += i > 0 ? zeros[i - 1] : 0;

            ones[n - 1 - i] = s[n - 1 - i] == '1';
            ones[n - 1 - i] += i > 0 ? ones[n - i] : 0;
        }

        int ans = 0;

        for (int i = 1; i < n; ++i)
        {
            ans = max(ans, zeros[i - 1] + ones[i]);
        }

        return ans;
    }
};