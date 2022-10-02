class Solution
{
    int last[26];
public:
    vector<int> partitionLabels(string s)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            last[s[i] - 'a'] = i;
        }
        
        vector<int> ans;
        int prev = 0;
        int c = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            c = max(c, last[s[i] - 'a']);
            
            if (i == c)
            {
                ans.push_back(i - prev + 1);
                prev = i + 1;
            }
        }
        
        return ans;
    }
};