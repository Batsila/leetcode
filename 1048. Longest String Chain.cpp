class Solution
{
public:
    int longestStrChain(vector<string>& words)
    {
        unordered_map<string, int> um;
        
        sort(words.begin(), words.end(), [](string a, string b)
             {
                 return a.size() < b.size();
             });
        
        int ans = 1;
        
        for (string word : words)
        {
            int c = 1;
            
            for (int i = 0; i < word.size(); ++i)
            {
                string p = word.substr(0, i) + word.substr(i + 1, word.size() + 1);
                
                auto itr = um.find(p);
                
                if (itr != um.end())
                {
                    c = max(c, itr->second + 1);
                }
            }
            
            um[word] = c;
            ans = max(ans, c);
        }
        
        return ans;
    }
};