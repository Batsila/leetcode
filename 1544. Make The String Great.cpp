class Solution
{
public:
    string makeGood(string str)
    {
        stack<char> s;
        
        for (char c : str)
        {
            if (not s.empty() and abs(s.top() - c) == 32)
            {
                s.pop();
            }
            else
            {
                s.push(c);
            }
        }
        
        string ans = "";
        
        while (not s.empty())
        {
            ans += s.top();
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};