class Solution
{
public:
    string stoneGameIII(vector<int>& stoneValue)
    {
        vector<int> dp(stoneValue.size() + 1, 0);

        for (int i = stoneValue.size() - 1; i >= 0; --i)
        {
            dp[i] = stoneValue[i] - dp[i + 1];

            if (i + 2 <= stoneValue.size())
            {
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
            }

            if (i + 3 <= stoneValue.size())
            {
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
            }
        }

        if (dp[0] > 0)
        {
            return "Alice";
        }
        else if(dp[0] < 0)
        {
            return "Bob";
        }
        else
        {
            return "Tie";
        }
    }
};