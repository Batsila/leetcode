class Solution
{
    int freqs[26];
    bool used[10000];
public:
    int minDeletions(string s)
    {
        for (char c : s)
        {
            ++freqs[c - 'a'];
        }
        
        int ans = 0;
        
        for (int i = 0; i < 26; ++i)
        {
            while (freqs[i] > 0 and used[freqs[i]])
            {
                ++ans;
                --freqs[i];
            }
            
            used[freqs[i]] = true;
        }
        
        return ans;
    }
};