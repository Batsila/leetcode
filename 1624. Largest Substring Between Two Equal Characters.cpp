class Solution
{
    int minIdx[26];
    int maxIdx[26];
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        vector<int> minIdx(26, s.size());
        vector<int> maxIdx(26, -1);

        for (int i = 0; i < s.size(); ++i)
        {
            minIdx[s[i] - 'a'] = min(minIdx[s[i] - 'a'], i);
            maxIdx[s[i] - 'a'] = max(maxIdx[s[i] - 'a'], i);
        }

        int ans = -1;

        for (int i = 0; i < 26; ++i)
        {
            if (maxIdx[i] - minIdx[i] > 0)
            {
                ans = max(ans, maxIdx[i] - minIdx[i] - 1);
            }
        }

        return ans;
    }
};