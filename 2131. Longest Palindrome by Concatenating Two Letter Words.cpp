class Solution
{
public:
    int longestPalindrome(vector<string>& words)
    {
        map<string, int> m;
        
        for (auto word : words)
        {
            ++m[word];
        }
        
        int ans = 0;
        bool hasCentral = false;
        
        for (auto p : m)
        {
            if (p.first[0] == p.first[1])
            {
                ans += 4 * (p.second / 2);
                
                if (not hasCentral and p.second % 2 == 1)
                {
                    ans += 2;
                    hasCentral = true;
                }
            }
            else if (p.first[0] < p.first[1])
            {
                string t = p.first;
                reverse(t.begin(), t.end());
                
                if (m.find(t) != m.end())
                {
                    ans += 4 * min(p.second, m[t]);
                }
            }
        }
        
        return ans;
    }
};