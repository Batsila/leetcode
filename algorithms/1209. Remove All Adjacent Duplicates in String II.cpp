class Solution 
{
public:
    string removeDuplicates(string str, int k) 
    {
        stack<pair<char, int>> s;
        s.push(make_pair(str[0], 1));
        
        int i = 1;
        
        while (i < str.size())
        {
            if (!s.empty() && s.top().first == str[i])
            {
                if (s.top().second + 1 == k)
                {
                    s.pop();
                }
                else
                {
                    auto p = make_pair(str[i], s.top().second + 1);
                    s.pop();
                    s.push(p);
                }
            }
            else
            {
                s.push(make_pair(str[i], 1));
            }
            
            ++i;
        }
        
        string ans = "";
        
        while (!s.empty())
        {
            auto p = s.top();
            
            for (int j = 0; j < p.second; ++j)
            {
                ans += p.first;
            }
            
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};