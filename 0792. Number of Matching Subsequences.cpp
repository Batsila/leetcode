class Solution
{
public:
    int numMatchingSubseq(string s, vector<string>& words)
    {
        unordered_map<string, int> m;
        
        for (string word : words)
        {
            ++m[word];
        }
        
        int ans = 0;
        
        for (auto [word, count] : m)
        {
            int ind = 0;
            
            for (char c : s)
            {
                if (ind < word.size() and word[ind] == c)
                {
                    ++ind;
                }
            }
            
            if (ind == word.size())
            {
                ans += count;
            }
        }
        
        return ans;
    }
};