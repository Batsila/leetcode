class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        vector<int> dp(26, 0);
        
        for (char c : s)
        {
            int current = c - 'a';
            int current_max_length = 0; 

            for (int previous = 0; previous < 26; ++previous)
            {
                if (abs(current - previous) <= k)
                {
                    current_max_length = max(current_max_length, dp[previous]);
                }
            }

            dp[current] = max(dp[current], current_max_length + 1);
        }

        return *max_element(dp.begin(), dp.end());
    }
};