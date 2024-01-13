class Solution
{
    int l[26];
public:
    int minSteps(string s, string t)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            ++l[s[i] - 'a'];
            --l[t[i] - 'a'];
        }

        int ans = 0;

        for (int i = 0; i < 26; ++i)
        {
            ans += abs(l[i]);
        }
        
        return ans / 2;
    }
};