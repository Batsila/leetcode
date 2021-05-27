class Solution
{
public:
    int maxProduct(vector<string>& words)
    {
        vector<int> bitmasks;
        
        for (string word : words)
        {
            int bitmask = 0;
            
            for (char ch : word)
            {
                bitmask |= 1 << (ch - 'a');
            }
            
            bitmasks.push_back(bitmask);
        }
        
        int ans = 0;
        
        for (int i = 0; i < words.size() - 1; ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                if (!(bitmasks[i] & bitmasks[j]))
                {
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        
        return ans;
    }
};