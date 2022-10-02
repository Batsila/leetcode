class Solution
{
public:
    string removeDuplicates(string str, int k)
    {
        stack<pair<char, int>> s;
        
        for (char c : str)
        {
            if (not s.empty() and s.top().first == c)
            {
                ++s.top().second;
            }
            else
            {
                s.push(make_pair(c, 1));
            }
            
            if (s.top().second == k)
            {
                s.pop();
            }
        }
        
        string ans = "";
        
        while (not s.empty())
        {
            for (int i = 0; i < s.top().second; ++i)
            {
                ans += s.top().first;
            }
            
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};