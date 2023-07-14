class Solution
{
public:
    int longestSubsequence(vector<int>& nums, int difference)
    {
        unordered_map<int, int> dp;
        int ans = 1;
        int current;

        for (int num : nums)
        {
            auto previous = dp.find(num - difference);
            current = previous != dp.end() ? previous->second + 1 : 1;
            ans = max(ans, current);
            dp[num] = current;
        }

        return ans;
    }
};