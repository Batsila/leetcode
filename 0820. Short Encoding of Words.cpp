class Solution
{
public:
    int minimumLengthEncoding(vector<string>& words)
    {
        set<string> s(words.begin(), words.end());
        
        for (string word : words)
        {
            for (int i = 1; i < word.size(); ++i)
            {
                s.erase(word.substr(i));
            }
        }
        
        int ans = 0;
        
        for (string word : s)
        {
            ans += word.size() + 1;
        }
        
        return ans;
    }
};