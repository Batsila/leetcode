class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> um(128);

        int ans = 0;
        int l = 0;
        int r = 0;

        while (r < s.size()) 
        {
            um[s[r]]++;

            while (um[s[r]] > 1) 
            {
                --um[s[l]];
                ++l;
            }

            ans = max(ans, r - l + 1);

            ++r;
        }

        return ans;
    }
};